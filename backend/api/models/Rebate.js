/**
* Roll.js
*
* @description :: TODO: You might write a short summary of how this model works and what it represents here.
* @docs        :: http://sailsjs.org/#!documentation/models
*/

module.exports = {
  identity:'Rebate',
  attributes: {
    user:{
      model:'User',
      index:true
    },
    start:{
      type: 'integer',
      defaultsTo: function(){Math.floor(Date.now()/1000)}
    },
    end:{
      type: 'integer',
      defaultsTo: function(){Math.floor(Date.now()/1000)}
    }
  }
};

