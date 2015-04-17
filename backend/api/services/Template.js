var cache={},queue={};
var fs=require('fs');
var ms=require('mustache');
console.log("Preloading partials...");
var top=fs.readFileSync("views/top.mustache","utf8");
var bot=fs.readFileSync("views/bot.mustache","utf8");
function render(view,data){
  return ms.render(cache[view],data,{top:top,bot:bot});
}
module.exports=function(res,view,data){
  if(cache[view] == null){
    if(queue[view]==null)
    {
      queue[view]=myqueue=[{res:res,data:data}];
      fs.readFile("views/"+view+".mustache","utf8",function(err,data){
        if(err){
          console.log(err);
        }
        cache[view]=data;
        for(i in myqueue){
          myqueue[i].res.send(render(view,myqueue[i].data));
          myqueue[i]=null;
        }
        myqueue=null;
      });
    }else
      queue[view].push({res:res,data:data});
  }else
    res.send(render(view,data));
}