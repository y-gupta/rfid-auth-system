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
      type:'number',
      defaultsTo:Math.floor(Date.now()/1000)
    },
    amount:{
      type:'number',
      defaultsTo:0
    },
    device:{
      model:'Device',
      index:true
    }
  }
};

