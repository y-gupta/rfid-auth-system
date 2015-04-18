/**
 * AdminController
 *
 * @description :: Server-side logic for managing admins
 * @help        :: See http://links.sailsjs.org/docs/controllers
 */
var dummy = {
  "username": "Rishit",
  "home":{"total_attendance": 1249,"expected":1273,"accuracy":"95.7%","extra_messing":457,"breakfast":"78.9%","lunch":"89.8%","dinner":"97.6%"},
  "AllHostels": []
      ,
  "Hostels":[
    {
    "Hostels":"zanskar",
    },
    {
    "Hostels":"shivalik",
    },
  ],
  "Graphs":{"Hostel":"Zanskar",
    "Pin":1234,
    "Attendance": [
    {"period": "monday breakfast" ,"expected": 756,"actual": 800},
    {"period": "monday lunch" ,"expected": 1245,"actual": 1345},
    {"period": "monday dinner" ,"expected": 1154,"actual": 1000},
    {"period": "tuesday breakfast","expected": 896,"actual": 900},
    {"period": "tuesday lunch" ,"expected": 1244,"actual": 1200},
    {"period": "tuesday dinner" ,"expected": 1024,"actual": 1142},
    {"period": "wednesday breakfast","expected": 654,"actual": 600}
    ],
    "Extramessing": [
    {"period": "monday breakfast" ,"expected": 756,"actual": 800},
    {"period": "monday lunch" ,"expected": 1245,"actual": 1345},
    {"period": "monday dinner" ,"expected": 1154,"actual": 1000},
    {"period": "tuesday breakfast","expected": 896,"actual": 900},
    {"period": "tuesday lunch" ,"expected": 1244,"actual": 1200},
    {"period": "tuesday dinner" ,"expected": 1024,"actual": 1142},
    {"period": "wednesday breakfast","expected": 654,"actual": 600}
    ],
    "Messrebate": [
    {"period": "monday breakfast" ,"expected": 756,"actual": 800},
    {"period": "monday lunch" ,"expected": 1245,"actual": 1345},
    {"period": "monday dinner" ,"expected": 1154,"actual": 1000},
    {"period": "tuesday breakfast","expected": 896,"actual": 900},
    {"period": "tuesday lunch" ,"expected": 1244,"actual": 1200},
    {"period": "tuesday dinner" ,"expected": 1024,"actual": 1142},
    {"period": "wednesday breakfast","expected": 654,"actual": 600}
    ]}
  ,
  "attendance":[
  {"UserId": "userA","Time": "12/12/12","Hostel": "Zanskar","Success": "success"},
  {"UserId": "userB","Time": "12/12/12","Hostel": "Zanskar","Success": "success"},
  {"UserId": "userC","Time": "12/12/12","Hostel": "Zanskar","Success": "success"},
  {"UserId": "userD","Time": "12/12/12","Hostel": "Zanskar","Success": "success"},
  {"UserId": "userE","Time": "12/12/12","Hostel": "Zanskar","Success": "success"},
  {"UserId": "userF","Time": "12/12/12","Hostel": "Zanskar","Success": "success"},
  {"UserId": "userG","Time": "12/12/12","Hostel": "Zanskar","Success": "success"},
  {"UserId": "userH","Time": "12/12/12","Hostel": "Zanskar","Success": "success"},
  {"UserId": "userI","Time": "12/12/12","Hostel": "Zanskar","Success": "success"}
  ],
  "UserData": [
  {"UserName": "userA","UserId":123 ,"RF-ID": 12345678,"Hostel": "Zanskar","EntryNo": "2013cs10251","Expiry":"12/12/12"},
  {"UserName": "userB","UserId":123 ,"RF-ID": 12345678,"Hostel": "Zanskar","EntryNo": "2013cs10251","Expiry":"12/12/12"},
  {"UserName": "userC","UserId":123 ,"RF-ID": 12345678,"Hostel": "Zanskar","EntryNo": "2013cs10251","Expiry":"12/12/12"},
  {"UserName": "userD","UserId":123 ,"RF-ID": 12345678,"Hostel": "Zanskar","EntryNo": "2013cs10251","Expiry":"12/12/12"},
  {"UserName": "userE","UserId":123 ,"RF-ID": 12345678,"Hostel": "Zanskar","EntryNo": "2013cs10251","Expiry":"12/12/12"},
  {"UserName": "userF","UserId":123 ,"RF-ID": 12345678,"Hostel": "Zanskar","EntryNo": "2013cs10251","Expiry":"12/12/12"},
  {"UserName": "userG","UserId":123 ,"RF-ID": 12345678,"Hostel": "Zanskar","EntryNo": "2013cs10251","Expiry":"12/12/12"},
  {"UserName": "userH","UserId":123 ,"RF-ID": 12345678,"Hostel": "Zanskar","EntryNo": "2013cs10251","Expiry":"12/12/12"}
  ],
  "MessRebate": [
  {"RebateId": 1234,"UserId": 4444,"TimeSpan": "13/12/12-12/12/13","Time": "12/12/12"},
  {"RebateId": 1235,"UserId": 4444,"TimeSpan": "13/12/12-12/12/13","Time": "12/12/12"},
  {"RebateId": 1236,"UserId": 4444,"TimeSpan": "13/12/12-12/12/13","Time": "12/12/12"},
  {"RebateId": 1237,"UserId": 4444,"TimeSpan": "13/12/12-12/12/13","Time": "12/12/12"},
  {"RebateId": 1238,"UserId": 4444,"TimeSpan": "13/12/12-12/12/13","Time": "12/12/12"},
  {"RebateId": 1239,"UserId": 4444,"TimeSpan": "13/12/12-12/12/13","Time": "12/12/12"},
  {"RebateId": 1230,"UserId": 4444,"TimeSpan": "13/12/12-12/12/13","Time": "12/12/12"},
  {"RebateId": 1231,"UserId": 4444,"TimeSpan": "13/12/12-12/12/13","Time": "12/12/12"},
  {"RebateId": 1232,"UserId": 4444,"TimeSpan": "13/12/12-12/12/13","Time": "12/12/12"}
  ],
  "ExtraMessing": [
  {"TransactionID": 12346,"UserId": 222555,"Amount": 45.50,"Time": "12:56 12/12/12"},
  {"TransactionID": 12347,"UserId": 222555,"Amount": 45.50,"Time": "12:56 12/12/12"},
  {"TransactionID": 12348,"UserId": 222555,"Amount": 45.50,"Time": "12:56 12/12/12"},
  {"TransactionID": 12349,"UserId": 222555,"Amount": 45.50,"Time": "12:56 12/12/12"},
  {"TransactionID": 12340,"UserId": 222555,"Amount": 45.50,"Time": "12:56 12/12/12"},
  {"TransactionID": 12341,"UserId": 222555,"Amount": 45.50,"Time": "12:56 12/12/12"},
  {"TransactionID": 12342,"UserId": 222555,"Amount": 45.50,"Time": "12:56 12/12/12"},
  {"TransactionID": 12343,"UserId": 222555,"Amount": 45.50,"Time": "12:56 12/12/12"},
  {"TransactionID": 12344,"UserId": 222555,"Amount": 45.50,"Time": "12:56 12/12/12"},
  {"TransactionID": 12345,"UserId": 222555,"Amount": 45.50,"Time": "12:56 12/12/12"}
  ],
  "masterCards": [
  {"ID": 12346,"RF-ID": 222555,"Hostel": "Zanskar"},
  {"ID": 12347,"RF-ID": 222555,"Hostel": "Zanskar"},
  {"ID": 12348,"RF-ID": 222555,"Hostel": "Zanskar"},
  {"ID": 12349,"RF-ID": 222555,"Hostel": "Zanskar"},
  {"ID": 12340,"RF-ID": 222555,"Hostel": "Zanskar"},
  {"ID": 12341,"RF-ID": 222555,"Hostel": "Zanskar"},
  {"ID": 12342,"RF-ID": 222555,"Hostel": "Zanskar"},
  {"ID": 12343,"RF-ID": 222555,"Hostel": "Zanskar"},
  {"ID": 12344,"RF-ID": 222555,"Hostel": "Zanskar"},
  {"ID": 12345,"RF-ID": 222555,"Hostel": "Zanskar"}
  ],
  "Admin": [
  {"Name": 12346,"Password": 222555,"Id":123,"Hostels": [{"Hostel":"Zanskar"}]},
  {"Name": 12347,"Password": 222555,"Id":123,"Hostels": [{"Hostel":"Zanskar"}]},
  {"Name": 12348,"Password": 222555,"Id":123,"Hostels": [{"Hostel":"Zanskar"}]},
  {"Name": 12349,"Password": 222555,"Id":123,"Hostels": [{"Hostel":"Zanskar"}]},
  {"Name": 12340,"Password": 222555,"Id":123,"Hostels": [{"Hostel":"Zanskar"},{"Hostel":"Shivalik"}]},
  {"Name": 12341,"Password": 222555,"Id":123,"Hostels": [{"Hostel":"Zanskar"}]},
  {"Name": 12342,"Password": 222555,"Id":123,"Hostels": [{"Hostel":"Zanskar"}]},
  {"Name": 12343,"Password": 222555,"Id":123,"Hostels": [{"Hostel":"Zanskar"}]},
  {"Name": 12344,"Password": 222555,"Id":123,"Hostels": [{"Hostel":"Zanskar"}]},
  {"Name": 12345,"Password": 222555,"Id":123,"Hostels": [{"Hostel":"Zanskar"}]}
  ],
  "isAdmin":true,
  "user": {"UserName": "userA","UserId": 99999,"RF-ID": 12345678,"Hostel": "Zanskar","EntryNo": "1452hh3325","Expiry": "12/12/12"},
  "admin":{"Name": 12340,"Password": 222555,"Hostels": ["Zanskar","Shivalik"]}
};


var admins={
  'admin@iitd':{name:'Yash Gupta',pass:'password',super:false,hostels:["zanskar","shivalik"]},
  'superadmin@iitd':{name:"Rohan Das",pass:'mypassword',super:true,hostels:[]}
};
module.exports = {
  update:function(req,res){
    sails.sockets.join(req.socket,'adminUpdates');  
    res.send({success:true});
  },
  home: function(req,res){
    ML.plot('zanskar',function(graph){
       var graph2=[];var j=0;
       for(i in graph){
        var date=new Date(graph[i].period*1000);
        graph[i].period=""+(date.getHours()>12?date.getHours()-12:date.getHours())+":"+(date.getMinutes()>9?"":"0")+date.getMinutes();
        graph2.push(graph[i]);
        j++;
       }
      dummy.AllHostels=graph2;
      Template(res,"index",dummy);
    });
  },
  logout:function(req,res){
    req.session.auth=false;
    Template(res,"login",{});
  },
	login: function(req,res){
    if(req.body && req.body.submit){
      var admin=admin=admins[req.body.email];
      if(admin && req.body.password==admin.pass)
      {
        req.session.auth=true;
        req.session.super=admin.super;
        req.session.admin=admin;
        return res.redirect("admin/home");
      }else{
        req.session.auth=false;
        return Template(res,"login",{msg:"Invalid Username/Password"});
      }
    }
    Template(res,"login",{});
  }
};

