/**
 * UserController
 *
 * @description :: Server-side logic for managing users
 * @help        :: See http://links.sailsjs.org/docs/controllers
 */

function getTimeFromStr(str){
  var parts = str.split("/");
  return Math.floor(new Date(parseInt("20"+parts[2], 10), parseInt(parts[1], 10) - 1, parseInt(parts[0], 10)).getTime()/1000);
};


module.exports = {
	login:function(req,res){
    //require('gm')
    //  .('./assets/user-images/'+req.props.user.image)
    //  .resize(100, 100)
    //  .toBuffer('PNG',function (err, buffer) {
    //    if (err) return handle(err);
    //    console.log('done!');
    //   });
    // console.log(req.props.user);
    var now=Math.floor(Date.now()/1000);
    Roll.create({user:req.props.user.id,device:req.props.device,hostel:req.props.hostel,success:true,time:now},
        function(err,roll){
          if(err == null){
            var meal=ML.meal(now);
            if(meal.meal=="break")
              return res.forbidden("This is break time");
            History.findOne({hostel:req.props.hostel,start:meal.start},function(err,hist){
              if(hist)
                History.update({hostel:req.props.hostel,start:meal.start},{attended:hist.attended+1},function(){});
              else
                History.create({hostel:req.props.hostel,start:meal.start,attended:1,expected:0},function(){});});

            require('fs').readFile('./assets/user-images/'+req.props.user.image,function(err,data){
              var img;
              console.log(err);
              if(err)
                img="";
              else
                img=data.toString('base64');
              res.send(_.extend(req.props.user,{success:true,master:false,image_data:img}));
            });
          }else
            res.serverError("Failed to record login/roll. "+err)
        });
  },
  rebate:function(req,res){
    
    var start=Math.floor(Date.now()/1000), end=start;
    if(req.query.nmeals == null || req.query.nmeals == 0){
      if(req.query.start != null && req.query.end != null)
      {
        start=getTimeFromStr(req.query.start);
        end=getTimeFromStr(req.query.end)+24*3600;
      }
    }else{
      start=ML.meal(start).start+120;
      end=start+req.query.nmeals*120;
    }
    if(start===end)
      res.badRequest("nmeals or start/end is required");
    else
      Rebate.create({user:req.props.user.id,start:start,end:end},
        function(err,rebate){
          if(err)
            res.serverError("Failed to insert rebate "+err)
          else res.send({id:rebate.id,success:true,start:new Date(start*1000).toString(),end:new Date(end*1000).toString(),nmeals:Math.floor((end-start)/120)});
        });
  },
  transact:function(req,res){
    var now=Math.floor(Date.now()/1000);
    if(req.query.amount == null)
      res.badRequest("  is required");
    else
      Transaction.create({user:req.props.user.id,amount:_.parseInt(req.query.amount),time:now,device:req.props.device},
        function(err,transaction){
          if(err == null)
            res.send({success:true,id:transaction.id})
          else
            res.serverError("Failed to record transaction. "+err)
        });
  }
};

