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
var plot = require('plotter').plot;
var randgen=require('randgen');
module.exports = {
  meal: mealInfo,
  info: function(hostel,time,next){
    var meal=mealInfo(time);

    if(meal.meal=="break"){
      var expected=0;
      History.findOne({hostel:hostel,start:meal.start+60},function (err,ml){
        console.log(ml);
        if(ml){
          expected=ml.expected;
        }else
          History.create({hostel:hostel,start:meal.start,expected:0,attended:0},function(){});
        return next(expected,0);
      });
      return;
    }

    var do_update=false;
    if(mealInfo(Math.floor(Date.now()/1000)).end==meal.end)
      do_update=true;
    var askednum=50;
    var start=meal.start-120*(askednum-1);

    History.find({hostel:hostel}).where({start:{'>=':start}}).exec(function(err,graph){
      if(err)
        console.log("ML.expected: DB error",err);
      var min=0,max=0,avg=0,sum=0,sumsq=0,num=0,attended=0;
      for(i in graph){
        if(max==0)
          min=max=graph[i].attended;
        if(max<graph[i].attended)
          max=graph[i].attended;
        if(min>graph[i].attended)
          min=graph[i].attended;
        sum+=graph[i].attended;
        sumsq+=graph[i].attended*graph[i].attended;
        num++;
        if(graph[i].start==meal.start)
          attended=graph[i].attended;
      }
      var sd=0;
      if(askednum>num)
        min=0;
      if(num==0)
        avg=sd=0;
      else 
      {  avg=sum/num;
        sd=Math.sqrt(sumsq/num-avg*avg)
      }
      var expected=Math.floor(randgen.rnorm(avg,sd));
      if(expected>avg*0.3+max*0.7)expected=avg*0.3+max*0.7;
      if(expected<avg*0.3+min*0.7)expected=avg*0.3+min*0.7;
      var old_expected=0;
      History.findOne({hostel:hostel,start:meal.start},function (err,ml){
        console.log(ml);
        if(ml){
          if(do_update)
            History.update({hostel:hostel,start:meal.start},{attended:attended},function(){});
          old_expected=ml.expected;
        }else
          History.create({hostel:hostel,start:meal.start,expected:0,attended:attended},function(){});
        next(old_expected,attended)
      });

      History.findOne({hostel:hostel,start:meal.start+120},function (err,ml){
        console.log(ml);
        if(!ml)
         History.create({hostel:hostel,start:(meal.start+120),expected:expected,attended:0},function(){});
      });
    });
  },
  plot: function(hostel,next){
    var now=Math.floor(Date.now()/1000);
    var num=50;
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
       next(graph);
      // var count=0;
     
      // console.log("graph size:",count);
      //TODO: plot it!
    });
  },
   renderplot: function(hostel,next){
    var now=Math.floor(Date.now()/1000);
    var num=50;
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
     
      // console.log("graph size:",count);
      //TODO: plot it!
      
      var img1={},img2={};
      for(start in graph){
        if(start<now-120*20)
          continue;
        img1[start]=graph[start].expected;
        img2[start]=graph[start].attended;
      }
      plot({
          data:       { 'actual' : img2,
              'expected' : img1},
          filename:   'ml/'+hostel+'.png',
          xlabel:     'Time',
          ylabel:   'footfall',
          time:     'hours'
      });
      next(graph);
    });
  },
};