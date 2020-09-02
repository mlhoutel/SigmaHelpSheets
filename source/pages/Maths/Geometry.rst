============================
Maths - Geometry
============================

.. contents:: Table of Contents
	:local: 

Triangle
---------------------------------

:Pythagorean Theorem:

.. admonition:: Pythagorean Theorem (Rectangle Triangle)
	
	:math:`c^2=a^2+b^2 \Leftrightarrow c=\sqrt{a^2+b^2}`
 

.. raw:: html
	
	<div id="pythagor_jxgbox" class="jxgbox" style="width:400px; height:400px;"></div>
	<script type="text/javascript">
	 	var board = JXG.JSXGraph.initBoard('pythagor_jxgbox', {boundingbox: [-10, 20, 20, -10], axis:true, pan: {enabled: false}, showCopyright:false, showNavigation:false});

	 	var p1 = board.create('point',[4, 0], {name:'', size:4, fixed:false, snapSizeY: 100, snapToGrid: true});
		var p2 = board.create('point',[0, 0], {name:'', size:4, fixed:true, color: 'blue'});
		var p3 = board.create('point',[0, 3], {name:'', size:4, fixed:false, snapSizeX: 100, snapToGrid: true});

		a = board.create('angle',[p1, p2, p3], {radius:0.5});
		
		// a.setAngle(function() {return Math.PI / 2; });

	 	var triangle = board.create('polygon',[p1,p2,p3], {fillOpacity:0.05});

		var p1_12 = board.create('point',[p1, board.create('transform', [-Math.PI/2, p2], {type:'rotate'})], {name:'', size:0});
		var p2_12 = board.create('point',[p2, board.create('transform', [Math.PI/2, p1], {type:'rotate'})], {name:'', size:0});
	 	var square_12 = board.create('polygon',[p1, p2, p1_12, p2_12], {fillOpacity:0.5, name:'B^2', withLabel: true, fillColor: 'blue'});
	 	
	 	
		var p1_13 = board.create('point',[p1, board.create('transform', [Math.PI/2, p3], {type:'rotate'})], {name:'', size:0});
		var p2_13 = board.create('point',[p3, board.create('transform', [-Math.PI/2, p1], {type:'rotate'})], {name:'', size:0});
	 	var square_13 = board.create('polygon',[p1, p3, p1_13, p2_13], {fillOpacity:0.5, name:'C^2', withLabel: true, fillColor: 'green'});
		
	
		var p1_23 = board.create('point',[p2, board.create('transform', [-Math.PI/2, p3], {type:'rotate'})], {name:'', size:0});
		var p2_23 = board.create('point',[p3, board.create('transform', [Math.PI/2, p2], {type:'rotate'})], {name:'', size:0});
	 	var square_23 = board.create('polygon',[p2, p3, p1_23, p2_23], {fillOpacity:0.5, name:'A^2', withLabel: true, fillColor: 'yellow'});

	 	board.update()
		board.on('update', function(e, i){
			square_12.name='B^2='+Math.round(square_12.Area())
			square_13.name='C^2='+Math.round(square_13.Area())
			square_23.name='A^2='+Math.round(square_23.Area())
		});
	 	
		board.update()
	</script>

:Thales Theorem:

Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod
tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,
quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo
consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse
cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non
proident, sunt in culpa qui officia deserunt mollit anim id est laborum.

.. admonition:: Thales Theorem (Homothety)
	
	:math:`\Large\frac{AD}{AB}=\frac{AE}{AC}=\frac{DE}{BC}`

.. raw:: html
	
	<div id="thales_jxgbox" class="jxgbox" style="width:400px; height:400px;"></div>
	<script type="text/javascript">
	 	var board = JXG.JSXGraph.initBoard('thales_jxgbox', {boundingbox: [-10, 20, 20, -10], axis:true, pan: {enabled: false}, showCopyright:false, showNavigation:false});

	 	var pA = board.create('point', [5, 10], {name:'A'});

	 	// Create a parallel
		var pB = board.create('point', [0, 0], {name:'B'});
		var pC = board.create('point', [10, 0], {name:'C'});


		var line_BC = board.create('line', [pB, pC], { strokecolor:'red' });

		var line_BA = board.create('line', [pB, pA]);
		var line_CA = board.create('line', [pC, pA]);

		var pParallel = board.create('point', [5, 3], { visible:false , name:' '});
		var line_DE = board.create('parallel', [line_BC, pParallel], { strokecolor:'red' });

		var pD = board.create('intersection', [line_DE, line_BA, 0], { name:'D', fillColor: 'blue'});
		var pE = board.create('intersection', [line_DE, line_CA, 0], { name:'E', fillColor: 'blue'});

	</script>


Circles and Ellipse
---------------------------------

.. admonition:: Circle Equation	

	:math:`(x-a)^2+(y-b)^2=r^2 \Leftrightarrow \sqrt{(x-a)^2+(y-b)^2}=r`

+---------------+---------------------------------+
| Diameter      | :math:`D=2 \times r`            |
+---------------+---------------------------------+
| Circumference | :math:`C=2 \times \pi \times r` |
+---------------+---------------------------------+
| Area          | :math:`A=\pi \times r^2`        |
+---------------+---------------------------------+

.. raw:: html
	
	<div id="circle_jxgbox" class="jxgbox" style="width:200px; height:200px;"></div>
	<script type="text/javascript">
	 	var board = JXG.JSXGraph.initBoard('circle_jxgbox', {boundingbox: [0, 10, 10, 0], axis:true, pan: {enabled: false}, showCopyright:false, showNavigation:false})
	 	var p1 = board.create('point', [4.0, 4.0])
	    var p2 = board.create('point', [2.0, 2.0])
	    var c1 = board.create('circle', [p1, p2])
	</script>

.. admonition:: Ellipse Equation	

	:math:`(\frac{(x-a)}{Hrad})^2+\frac{(y-b)}{Vrad})^2=1 \Leftrightarrow \sqrt{(\frac{(x-a)}{Hrad})^2+\frac{(y-b)}{Vrad})^2}=1`

.. raw:: html
	
	<div id="ellipse_jxgbox" class="jxgbox" style="width:200px; height:200px;"></div>
	<script type="text/javascript">
	 	var board = JXG.JSXGraph.initBoard('ellipse_jxgbox', {boundingbox: [-10, 10, 10, -10], axis:true, pan: {enabled: false}, showCopyright:false, showNavigation:false})

		// Create an Ellipse by three points
		var ellipse_A = board.create('point', [-1,4]);
		var ellipse_B = board.create('point', [-1,-4]);
		var ellipse_C = board.create('point', [1,1]);
		var ellipse_el = board.create('ellipse',[ellipse_A,ellipse_B,ellipse_C]);

	</script>


Vectors
---------------------------------

Tensors
---------------------------------

https://www.youtube.com/watch?v=TvxmkZmBa-k

Matrix
---------------------------------

https://www.youtube.com/watch?v=rowWM-MijXU

Quaternions
---------------------------------