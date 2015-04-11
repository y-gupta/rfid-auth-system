/**
 * DeviceController
 *
 * @description :: Server-side logic for managing devices
 * @help        :: See http://links.sailsjs.org/docs/controllers
 */

module.exports = {
  init: function (req, res) {
    require('fs').readFile("ml/results/"+req.props.hostel+".png",function(err,image_data){
      var image = "";
      if(err == null){
        image = image_data.toString('base64');
      }      
      res.send({
      'success':true,
      'hostel': req.props.hostel,
      'device': req.props.device,
      'image': image,
      'expected':290,
      'attended':102,
      'meal':'lunch'
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
      User.create({name:'guest user', rfid:req.query.rfid,entry:'N/A', hostel:req.props.hostel},function(err,user){
          if(err==null)
            res.send({id:user.id,success:true})
          else res.serverError('Failed to insert new user. '+err)
        });
  }
};

