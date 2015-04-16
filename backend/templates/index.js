var fs=require('fs');
var _=require('lodash');
var Mustache=require('mustache');
data=JSON.parse(fs.readFileSync('./data.json'),'utf8');
var files=fs.readdirSync('./final/');
var tp = fs.readFileSync('./final/top.mustache','utf8');
var bt = fs.readFileSync('./final/bot.mustache','utf8');
function compile(file){
  fs.writeFileSync('./compiled/'+file,Mustache.render(fs.readFileSync('./'+file,'utf8'), data,{"top":tp,"bot":bt}));
}
_.each(files,function(file){compile('final/'+file)});
