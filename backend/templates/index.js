var fs=require('fs');
var _=require('lodash');
var Mustache=require('mustache');
data=JSON.parse(fs.readFileSync('./data.json'),'utf8');
var files=fs.readdirSync('./new/');
var menue = fs.readFileSync('./menu.html','utf8');
function compile(file){
  fs.writeFileSync('./compiled/'+file,Mustache.render(menue, data, {content:Mustache.render(fs.readFileSync('./'+file,'utf8'))} ));
}
_.each(files,function(file){compile('new/'+file)});
