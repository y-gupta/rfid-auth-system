/**
* Master.js
*
* @description :: TODO: You might write a short summary of how this model works and what it represents here.
* @docs        :: http://sailsjs.org/#!documentation/models
*/

module.exports = {
  identity:'Master',
  attributes: {
    rfid:{
      type: 'string',
      unique: true,
      defaultsTo: '0123456789abcdef'
    },
    device:{
      model:'Device'
    }
  }
};

