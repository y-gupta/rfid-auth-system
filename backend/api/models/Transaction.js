  /**
* Transaction.js
*
* @description :: TODO: You might write a short summary of how this model works and what it represents here.
* @docs        :: http://sailsjs.org/#!documentation/models
*/

module.exports = {
  identity:'Transaction',
  attributes: {
    user:{
      model:'User',
      index:true
    },
    time:{
      type:'integer'
    },
    amount:{
      type:'integer',
      defaultsTo:0
    },
    device:{
      model:'Device',
      index:true
    }
  },
  afterCreate:function(row,next){
    ML.extra_messing('zanskar',function(em){
      sails.sockets.broadcast('adminUpdates','messing',em);
    });
    next();
  }
};

