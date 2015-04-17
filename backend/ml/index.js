// var DS=require('digitalsignals');
// var dft = new DS.DFT(10, 44100);
// dft.forward([1,2,3,1,2,3,1,2,3,1]);
// var spectrum = dft.spectrum;

// function calc

// console.log(dft,spectrum);

var synaptic = require('synaptic'); // this line is not needed in the browser
var Neuron = synaptic.Neuron,
    Layer = synaptic.Layer,
    Network = synaptic.Network,
    Trainer = synaptic.Trainer,
    Architect = synaptic.Architect;

var past_count=7,output_precision=10;

var network = new Architect.Perceptron(past_count,40,output_precision+1);
var trainer=new Trainer(network);

function makeQuerySet(past,max){
  var i,input=[];
  for(i=0;i<past_count;i++)
  {
    if(past[i]>max)
      past[i]=max;
    if(past[i]<0)
      past[i]=0;
    input.push(past[i]/max);
  }
  return input;
}
function makeTrainSet(past,now,max){
  var i,set={input:makeQuerySet(past,max),output:[]};
  for(i=0;i<=output_precision;i++)
    set.output.push(0);
  if(now>max)
    now=max;
  if(now<0)
    now=0;
  set.output[Math.floor(now/max*output_precision)]=1;
  return set;
}
function parseResultSet(output,max){
  var i;
  var sum=0,sqsum=0,total=0,sd=0,mean=0;
  for(i=0;i<=output_precision;i++)
  {  
    var x=i/output_precision*max;
    sum+=x*output[i];
    sqsum+=x*x*output[i];
    total+=output[i];
  }
  mean=sum/total;
  sd=Math.sqrt(sqsum/total-mean*mean);
  return {mean:mean,sd:sd};
}
trainer.train([
  makeTrainSet([100,1],100,100),
  makeTrainSet([480,100,460],100,100),
  // makeTrainSet([300,300,300],300,500),
  // makeTrainSet([120,104,110],100,500),
  // makeTrainSet([400,406,490],420,500),
  // makeTrainSet([220,250,204],259,500),
  // makeTrainSet([350,310,200],230,500),
  // makeTrainSet([300,100,300],100,500),
  // makeTrainSet([480,102,220],130,500),
  // makeTrainSet([300,100,300],100,500),
]);
var res;
console.log(parseResultSet(network.activate(makeQuerySet([250,440,300],500)),500));
console.log(parseResultSet(network.activate(makeQuerySet([300,300,300],500)),500));
console.log(parseResultSet(network.activate(makeQuerySet([300,400,300],500)),500));