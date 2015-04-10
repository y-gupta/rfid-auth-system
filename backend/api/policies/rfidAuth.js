/**
 * sessionAuth
 *
 * @module      :: Policy
 * @description :: Simple policy to allow any authenticated user
 *                 Assumes that your login action in one of your controllers sets `req.session.authenticated = true;`
 * @docs        :: http://sailsjs.org/#!documentation/policies
 *
 */
module.exports = function(req, res, next) {
  req.wantsJSON=true;
  // User is allowed, proceed to the next policy, 
  // or if this is the last policy, the controller
  if(req.props == null)
    req.props = {};

  if(req.query.rfid != null){
    User.findOne({rfid:req.query.rfid}).exec(function(err,user){
      if(user != null){
        req.props.user=user;
        req.props.master=false;
        console.log("User RFID detected");
        if(user.hostel === req.props.hostel)
          next();
        else{
            Roll.create({user:req.props.user.id,device:req.props.device,hostel:req.props.hostel,success:false},
            function(err,roll){
              if(err == null)
                res.forbidden('User of '+user.hostel+' not allowed in '+req.props.hostel);
              else
                res.serverError("Failed to record login/roll. "+err)
            });
        }
      }else{
        Master.findOne({rfid:req.query.rfid}).populate('device').exec(function(err,master){
          if(master!=null){
            console.log("Master RFID detected");
            res.redirect('device/login?mac='+req.query.mac+'&pin='+master.device.pin);
            // require('http').get(sails.getBaseurl()+'/device/login?mac='+req.query.mac+'&pin='+master.device.pin,
            //     function(resp){
            //       total_resp="";
            //       resp.on('data',function(chunk){total_resp+=chunk})
            //         .on('end',function(){res.send(total_resp)})
            //     })
            //   .on('error',function(e){res.serverError("Unable to redirect to master login")})
          }else
            res.forbidden('User/Master RFID invalid');  
        });
      }
    });
  }else
    res.badRequest('User/Master RFID missing');
};