module.exports = function(req, res, next) {
  // User is allowed, proceed to the next policy, 
  // or if this is the last policy, the controller
  if(req.query.pin != null){
    if(req.props.pin==req.query.pin)
      next();
    else
      return res.forbidden('Device PIN invalid');  
  }else
    return res.badRequest('Device PIN missing');
};