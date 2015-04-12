var fs=require('fs');
var _=require('lodash');
var Mustache=require('mustache');
data=JSON.parse(fs.readFileSync('./data.json'),'utf8');
var files=fs.readdirSync('./new');
var menue = Mustache.render(fs.readFileSync('../menue.html','utf8'),data);
function compile(file){
  fs.writeFileSync('./compiled/'+file,Mustache.render(menue, data, {content:Mustache.render(fs.readFileSync('./'+file,'utf8'))} ));
}
_.each(files,function(file){compile('admin/'+file)});
