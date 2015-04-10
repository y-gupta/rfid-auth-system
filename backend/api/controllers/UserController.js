/**
 * UserController
 *
 * @description :: Server-side logic for managing users
 * @help        :: See http://links.sailsjs.org/docs/controllers
 */

module.exports = {
	login:function(req,res){
    Roll.create({user:req.props.user.id,device:req.props.device,hostel:req.props.hostel,success:true},
        function(err,roll){
          if(err == null)
            res.send(_.extend(req.props.user,{success:true,master:false}));
          else
            res.serverError("Failed to record login/roll. "+err)
        });
  },
  rebate:function(req,res){
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

