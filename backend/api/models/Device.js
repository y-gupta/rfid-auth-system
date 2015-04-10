/**
* Device.js
*
* @description :: TODO: You might write a short summary of how this model works and what it represents here.
* @docs        :: http://sailsjs.org/#!documentation/models
*/

module.exports = {
  identity:'Device',
  attributes: {
    mac:{
      type: 'string',
      defaultsTo: '00-00-00-00-00-00',
      unique:true
    },
    pin:{
      type: 'string',
      defaultsTo: '0000'
    },
    hostel:{
      type: 'string',
      defaultsTo: 'zanskar' 
    }
  }
};

