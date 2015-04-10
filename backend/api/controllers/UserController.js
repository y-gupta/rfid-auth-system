/**
 * UserController
 *
 * @description :: Server-side logic for managing users
 * @help        :: See http://links.sailsjs.org/docs/controllers
 */

module.exports = {
	login:function(req,res){
    //TOOD: insert row into roll
    res.send(_.extend(req.props.user,{success:true,master:false}));
  },
  rebate:function(req,res){
    res.send({success:true});
  },
  transaction:function(req,res){
    res.send({success:true});
  }
};

