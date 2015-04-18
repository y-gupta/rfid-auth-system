var plot = require('plotter').plot;
plot({
    data:       { 'actual' : {1357162672: 22, 1357162782: 23, 1357162892: 24},
        'expected' : {1357162672: 21, 1357162782: 26, 1357162892: 25} },
    filename:   'output.png',
    xlabel:     'Time',
    ylabel: 	'footfall',
    time: 		'hours',
    moving_avg: 3
});