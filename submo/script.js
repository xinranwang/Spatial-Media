

var canvas = document.getElementById("test");

var ctx = canvas.getContext("2d");

var img = new Image();

img.onload = function() {
	ctx.drawImage(img, 0, 0,980,440,0,0,980,440);
};

img.src = "http://128.122.151.22/axis-cgi/mjpg/video.cgi?";

window.setInterval("refreshCanvas()", 20);

var pillars = [];
for(var i = 0; i < 5; i++) {
	pillars.push(new Pillar (300 * i, canvas.height / 3, 1, canvas.height / 3));
}
for(var i = 0; i < 10; i++) {
	pillars.push(new Pillar (40 + 200 * i, canvas.height / 3, 3, canvas.height / 3));
}

pillars.sort(function(a, b) {return a.x - b.x;});


var frames = [];
for (var i = 0; i < pillars.length - 1; i++) {
	var p = pillars[i];
	var next = pillars[i+1];
	if(next.left - p.right > 10 && p.right < canvas.width) {
		var frame = new PillarFrame(p.right, p.y, next.left - p.right, p.height);
		frames.push(frame);
	}
};
// for(var i in pillars) {
// 	console.log(pillars[i]);
// }
for(var i in frames) {
	console.log(frames[i]);
}

function refreshCanvas(){
  	ctx.drawImage(img, 0, 0,980,440,0,0,980,440);

	ctx.rect(0, 0, canvas.width, canvas.height / 3);
	ctx.rect(0, canvas.height * 2 / 3, canvas.width, canvas.height / 3);
	ctx.fillStyle = "#000000";
	ctx.fill();
	for(var i in pillars) {
    	pillars[i].draw();
	}
	for (var i in frames) {
		frames[i].draw();
	}

	// draw the film rectangles: up row
	ctx.beginPath();
	for(var i=1; i<24; i++){
		ctx.rect(i*40+20, 150, 20, 20);
	}
	ctx.fillStyle = "#dddddd";
	ctx.fill();

	// draw the film rectangles: down row
	ctx.beginPath();
	for(var i=1; i<24; i++){
		ctx.rect(i*40+20, 470, 20, 20);
	}
	ctx.fillStyle = "#dddddd";
	ctx.fill();

	// draw the title
	ctx.font="100px Calibri";
	ctx.lineWidth = 3;
		ctx.strokeStyle = "#A3A692";
	ctx.strokeText("s",430,120);

		ctx.strokeStyle = "#F2C288";
	ctx.strokeText("u",460,120);

		ctx.strokeStyle = "#F2AD85";
	ctx.strokeText("b",500,120);

		ctx.strokeStyle = "#F2887E";
	ctx.strokeText("m",544,120);

		ctx.strokeStyle = "#F25757";
	ctx.strokeText("o",615,120);

};


function Pillar (x, y, dist, height) {
	this.x = x;
	this.y = y;
	this.dist = dist;
	this.height = height;
	this.size = 30 + 20 / this.dist;
	this.left = this.x - this.size / 2;
	this.right = this.left + this.size;
};

Pillar.prototype.draw = function () {
	ctx.rect(this.left, this.y, this.size, this.height);
	ctx.fill();
};

function PillarFrame (x, y, w, h) {
	this.x = x;
	this.y = y;
	this.w = w;
	this.h = h;
}

PillarFrame.prototype.draw = function() {
	//ctx.strokeStyle="#688E41";
	//ctx.lineWidth = 5;
	//ctx.strokeRect(this.x, this.y, this.w, this.h);
}



$(document).ready(function() {
	for(var i in frames) {
		$(".container").append('<button class="capture capture'+i+'" value="'+ i +'"> </button>')
	}

	
		
	$('.capture').click(function() {
		var i = $(this).attr("value");
		//$.get("/capture/" + i);
		// add "saved"
		$(".container").append('<p class="clicked" style="left:' + frames[i].x +'px; ">Saved</p>')
		// create a new canvas
		//$(".container").append('<canvas id="myCanvas'+i+'"></canvas>')
		//$.get("/capture?frame_id=" + i + "&x=" + frames[i].x + "&y=" + frames[i].y + "&w=" + frames[i].w + "&h=" + frames[i].h);
		// add "done" button
		$(".container").append('<button class="done">Done</button>')
		
		// draw the 7 canvases on top of the main canvas
		var img0 = document.getElementById("test");
		if(i==0){
			$(".container").append('<canvas id="myCanvas0" width="172px" height="220px"></canvas>')
			var canvas0 = document.getElementById("myCanvas0");
			var ctx0 = canvas0.getContext("2d");
			ctx0.drawImage(img0, 54,210,172,220,0,0,172,220);
		}
		if(i==1){
			$(".container").append('<canvas id="myCanvas1" width="24px" height="220px"></canvas>')
			var canvas1 = document.getElementById("myCanvas1");
			var ctx1 = canvas1.getContext("2d");
			ctx1.drawImage(img0, 256,210,24,220,0,0,24,220);
		}
		if(i==2){
			$(".container").append('<canvas id="myCanvas2" width="105px" height="220px"></canvas>')
			var canvas2 = document.getElementById("myCanvas2");
			var ctx2 = canvas2.getContext("2d");
			ctx2.drawImage(img0, 321,210,105,220,0,0,105,220);
		}
		if(i==3){
			$(".container").append('<canvas id="myCanvas3" width="126px" height="220px"></canvas>')
			var canvas3 = document.getElementById("myCanvas3");
			var ctx3 = canvas3.getContext("2d");
			ctx3.drawImage(img0, 454,210,126,220,0,0,126,220);
		}
		if(i==4){
			$(".container").append('<canvas id="myCanvas4" width="172px" height="220px"></canvas>')
			var canvas4 = document.getElementById("myCanvas4");
			var ctx4 = canvas4.getContext("2d");
			ctx4.drawImage(img0, 654,210,172,220,0,0,172,220);
		}
		if(i==5){
			$(".container").append('<canvas id="myCanvas5" width="27px" height="220px"></canvas>')
			var canvas5 = document.getElementById("myCanvas5");
			var ctx5 = canvas5.getContext("2d");
			ctx5.drawImage(img0, 854,210,27,220,0,0,27,220);
		}
		if(i==6){
			$(".container").append('<canvas id="myCanvas6" width="39px" height="220px"></canvas>')
			var canvas6 = document.getElementById("myCanvas6");
			var ctx6 = canvas6.getContext("2d");
			ctx6.drawImage(img0, 920,210,39,220,0,0,39,220);
		}
		
		// click the "done" btn
	$('.done').click(function() {
		$(".result").append('<p id="yourPhoto">Here is your</p>')
		html2canvas(document.body, {
			onrendered: function(canvas) {
				canvas.id = "myCanvas";
				document.body.appendChild(canvas);
			},
			width: 960,
			height: 500,
			taintTest: false,
			allowTaint: true,
			proxy: "http://128.122.151.221/axis-cgi/mjpg/video.cgi?"
		});
	});
	});
	
		

	$("#test").click(function(e){
		console.log(e.offsetX, e.offsetY);


		var x = e.offsetX;
		var y = e.offsetY;

		for(var i in frames) {
			var f = frames[i];
			if(x > f.x && x < f.x + f.w && y > f.y && f < f.y + f.h) {
				$.get("/capture/" + i);
				console.log(i);
			}
		}
	});
});
