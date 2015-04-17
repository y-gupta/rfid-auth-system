function mealInfo(time){
  var res={};
  res.start=Math.floor(time/60);
  res.num=res.start%6;
  res.start*=60;
  res.end=res.start+60;
  if(res.num==0)
    res.meal='breakfast'
  else if(res.num==2) 
    res.meal='lunch'
  else if(res.num==4)
    res.meal='dinner'
  else
    res.meal='break';
  return res;
};
module.exports = {
  meal: mealInfo,
  info: function(hostel,time,next){
    var meal=mealInfo(time);
    var do_update=false;
    if(mealInfo(Math.floor(Date.now()/1000)).end==meal.end)
      do_update=true;
    var askednum=100;
    var start=meal.end-120*(askednum-1);

    History.find({hostel:hostel}).where({start:{'>=':start}}).exec(function(err,graph){
      if(err)
        console.log("ML.expected: DB error",err);
      var min=0,max=0,avg=0,sum=0,num=0,attended=0;
      for(i in graph){
        if(max==0)
          min=max=graph[i].attended;
        if(max<graph[i].attended)
          max=graph[i].attended;
        if(min>graph[i].attended)
          min=graph[i].attended;
        sum+=graph[i].attended;
        num++;
        if(graph[i].start==meal.start)
          attended=graph[i].attended;
      }
      if(askednum>num)
        min=0;
      if(num==0)
        avg=0;
      else 
        avg=sum/num;
      var expected=Math.floor(min+(Math.random())*(max-min));
      History.findOne({hostel:hostel,start:meal.start},function (err,ml){
        console.log(ml);
        if(ml)
        {
          if(do_update)
            History.update({hostel:hostel,start:meal.start},{attended:attended},function(){});
          return next(ml.expected,attended);
        }
        History.create({hostel:hostel,start:meal.start,expected:expected,attended:attended},function(){});
        return next(expected,attended);
      });
    });
  },
  plot: function(hostel,next){
    var now=Math.floor(Date.now()/1000);
    var num=100;
    var start=mealInfo(now).start-120*(num-1);
    // Roll.create({user:req.props.user.id,device:req.props.device,hostel:req.props.hostel,success:true},
    var graph={};
    for(var i=0;i<num;i++)
      graph[start+i*120]=({period:(start+i*120),expected:0,attended:0});
    History.find({hostel:hostel}).where({start:{'>=':start}}).exec(function(err,hists){
      if(err)
        console.log("ML.plot: DB error",err);
      for(i in hists)
      {
        if(!graph[hists[i].start])
          graph[hists[i].start]=({period:hists[i].start,expected:0,attended:0});
        graph[hists[i].start].expected=hists[i].expected;
        graph[hists[i].start].attended=hists[i].attended;
       }
      // var count=0;
      // for(i in graph)
      //   count++;
      // console.log("graph size:",count);
      //TODO: plot it!
      return next(graph);
    });
  },
};