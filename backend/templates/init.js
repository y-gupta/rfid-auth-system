var req=require("http");
var job=function(){
  req.get("http://localhost:1337/device/init?mac=100",function(err,res,body){
    console.log(body);
    setTimeout(job,10000);
});
}
job();