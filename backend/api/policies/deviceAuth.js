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
  console.log("Request (Device Auth): ",req.query);
  req.wantsJSON=true;
  // User is allowed, proceed to the next policy, 
  // or if this is the last policy, the controller
  if(req.query.mac != null){
    Device.findOne({mac:req.query.mac}).exec(function(err,device){
      if(device != null){
        if(req.props == null)
          req.props = {};
        req.props.hostel=device.hostel;
        req.props.pin=device.pin;
        req.props.device=device.id;
        req.props.mac=device.mac;
        next();
      }else
        return res.forbidden('Device MAC invalid');  
    });
  }else
    return res.badRequest('Device MAC missing');
};