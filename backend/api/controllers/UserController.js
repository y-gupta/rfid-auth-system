/**
 * UserController
 *
 * @description :: Server-side logic for managing users
 * @help        :: See http://links.sailsjs.org/docs/controllers
 */

module.exports = {
	login:function(req,res){
    //require('gm')
    //  .('./assets/user-images/'+req.props.user.image)
    //  .resize(100, 100)
    //  .toBuffer('PNG',function (err, buffer) {
    //    if (err) return handle(err);
    //    console.log('done!');
    //   });
    console.log(req.props.user);
    Roll.create({user:req.props.user.id,device:req.props.device,hostel:req.props.hostel,success:true},
        function(err,roll){
          if(err == null){
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
    //if(req.query.from == null || req.query.to == null || req.query. == null)
    res.send({success:true});
  },
  transact:function(req,res){
    if(req.query.amount == null)
      res.badRequest("amount is required");
    else
      Transaction.create({user:req.props.user.id,amount:_.parseInt(req.query.amount),device:req.props.device},
        function(err,transaction){
          if(err == null)
            res.send({success:true,id:transaction.id})
          else
            res.serverError("Failed to record transaction. "+err)
        });
  }
};

