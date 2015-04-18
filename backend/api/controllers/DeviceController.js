/**
 * DeviceController
 *
 * @description :: Server-side logic for managing devices
 * @help        :: See http://links.sailsjs.org/docs/controllers
 */

module.exports = {
  init: function (req, res) {
    var now=Math.floor(Date.now()/1000);
    ML.plot(req.props.hostel,function(){
    ML.info(req.props.hostel,now,function(expected,attended){
      require('fs').readFile("ml/"+req.props.hostel+".png",function(err,image_data){
        var image = "";
        if(err == null){
          image = image_data.toString('base64');
        }      
        res.send({
        'success':true,
        'hostel': req.props.hostel,
        'device': req.props.device,
        'image': image,
        'expected':expected,
        'attended':attended,
        'meal': ML.meal(now).meal
        });
      });
    });
    });
  },
  login: function (req,res){
    res.send({pin:req.props.pin,success:true,master:true});    
  },
  addcard: function(req,res){
    if(req.query.rfid == null)
      res.badRequest('rfid of new card is required');
    else
      Master.findOne({rfid:req.query.rfid},function(err,user){
        if(user == null)
          User.create({name:'guest user', rfid:req.query.rfid,entry:'N/A', hostel:req.props.hostel},function(err,user){
            if(err==null)
              res.send({id:user.id,success:true})
            else res.serverError('Failed to insert new user. '+err)
          });
        else
          res.serverError('A mastercard is registered with this RFID')
      })
  },
  addmaster: function(req,res){
    if(req.query.rfid == null)
      res.badRequest('rfid of new card is required')
    else
      User.findOne({rfid:req.query.rfid},function(err,user){
        if(user==null)
          Master.create({rfid:req.query.rfid,device: req.props.device},function(err,user){
              if(err==null)
                res.send({id:user.id,success:true})
              else res.serverError('Failed to insert new mastercard. '+err)
            })
        else
          res.serverError('A user already exists with this RFID');
    })
  },
  removecard:function(req,res){
    if(req.query.rfid == null)
      res.badRequest('rfid of the card is required');
    else
      User.destroy({rfid:req.query.rfid, hostel:req.props.hostel},function(err,user){
          if(err==null)
            res.send({success:true})
          else res.forbidden('Failed to delete card. '+err)
        });
  },
  allow:function(req,res){
    var now=Math.floor(Date.now()/1000);
    if(meal.meal=="break")
      return res.forbidden("This is break time");
    User.findOrCreate({name:req.props.hostel+" admin",entry:"N/A"},function(err,user){
      if(err)
        res.serverError("Failed to create/find admin user accountt");
      else
        Roll.create({user:user.id,device:req.props.device,hostel:req.props.hostel,success:true,time:now},
          function(err,roll){
           if(err == null){
            var meal=ML.meal(now);
             History.findOne({hostel:req.props.hostel,start:meal.start},function(err,hist){
              if(hist)
                History.update({hostel:req.props.hostel,start:meal.start},{attended:hist.attended+1},function(){});
              else
                History.create({hostel:req.props.hostel,start:meal.start,attended:1},function(){});});
             res.send({success:true});
           }
           else
             res.serverError("Failed to record login/roll. "+err)
          });
   });
  }
};

