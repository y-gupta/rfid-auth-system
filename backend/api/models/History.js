module.exports = {
  attributes: {
    hostel: 'string',
    start: 'integer',
    expected: 'integer',
    attended: 'integer'
  },
  afterUpdate:function(entry,next){
    // var date=new Date(entry.start*1000);
    // res={};
    // res.period=""+(date.getHours()>12?date.getHours()-12:date.getHours())+":"+(date.getMinutes()>9?"":"0")+date.getMinutes();
    // res.attended=entry.attended;
    // res.expected=entry.expected;
    ML.plot('zanskar',function(graph){
      var graph2=[];
      for(i in graph){
        var date=new Date(graph[i].period*1000);var tmp={};
        tmp.y=""+(date.getHours()>12?date.getHours()-12:date.getHours())+":"+(date.getMinutes()>9?"":"0")+date.getMinutes();
        tmp.a=graph[i].attended;
        tmp.b=graph[i].expected;
        graph2.push(tmp);
       }
    sails.sockets.broadcast('adminUpdates','update',graph2);
  });
    next();
  },
  afterCreate:function(entry,next){
    // var date=new Date(entry.start*1000);
    // res={};
    // res.period=""+(date.getHours()>12?date.getHours()-12:date.getHours())+":"+(date.getMinutes()>9?"":"0")+date.getMinutes();
    // res.attended=entry.attended;
    // res.expected=entry.expected;
     ML.plot('zanskar',function(graph){
      var graph2=[];
      for(i in graph){
        var date=new Date(graph[i].period*1000);var tmp={};
        tmp.y=""+(date.getHours()>12?date.getHours()-12:date.getHours())+":"+(date.getMinutes()>9?"":"0")+date.getMinutes();
        tmp.a=graph[i].attended;
        tmp.b=graph[i].expected;
        graph2.push(tmp);
       }
    sails.sockets.broadcast('adminUpdates','create',graph2);
  });
    next();
  }
};

