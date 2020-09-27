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


Circles
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
	
	<div id="circle_jxgbox" class="jxgbox" style="width:400px; height:400px;"></div>
	<script type="text/javascript">
	 	var board = JXG.JSXGraph.initBoard('circle_jxgbox', {boundingbox: [0, 10, 10, 0], axis:true, pan: {enabled: false}, showCopyright:false, showNavigation:false})
	 	var p1 = board.create('point', [4.0, 4.0])
	    var p2 = board.create('point', [2.0, 2.0])
	    var c1 = board.create('circle', [p1, p2])
	</script>


Ellipses
---------------------------------

.. admonition:: Ellipse Equation	

	:math:`(\frac{(x-a)}{Hrad})^2+\frac{(y-b)}{Vrad})^2=1 \Leftrightarrow \sqrt{(\frac{(x-a)}{Hrad})^2+\frac{(y-b)}{Vrad})^2}=1`

+---------------------+---------------------------------+
| Semi-major Diameter | :math:`Da=2 \times a`           |
+---------------------+---------------------------------+
| Semi-minor Diameter | :math:`Db=2 \times b`           |
+---------------------+---------------------------------+
| h                   | :math:`\frac{(a-b)^2}{(a+b)^2}` |
+---------------------+---------------------------------+
| Exentricity e       | :math:`\frac{\sqrt{a^2-b^2}}{a}`|
+---------------------+---------------------------------+
| Area                | :math:`A=\pi \times a \times b` |
+---------------------+---------------------------------+

.. admonition:: It does not exist and formula for the exact formula of the Circumference, here's some approximations (in order of precision):

:Popular approximation: (5%) :math:`2 \pi \sqrt{\frac{a^2+b^2}{2}}`

:Ramanujan first approximation: (0.005%) :math:`\pi (3 (a+b) - \sqrt{(3a+b)(a+3b)})`

:Ramanujan second approximation: (0.0000005%) :math:`\pi (a+b)(1+\frac{3h}{10+\sqrt{4-3h}}`

:Series approximation: (0.0000...%) :math:`\pi (a+b)(1 + \frac{h}{4} + \frac{h^2}{64} + \frac{h^3}{256} + \frac{25h^4}{16384} + ... )`

.. raw:: html
	
	<div id="ellipse_jxgbox" class="jxgbox" style="width:400px; height:400px;"></div>
	<script type="text/javascript">

	 	var board = JXG.JSXGraph.initBoard('ellipse_jxgbox', {boundingbox: [-10, 10, 10, -10], axis:true, pan: {enabled: false}, showCopyright:false, showNavigation:false})

		// Create an Ellipse by three points
		var ellipse_A = board.create('point', [-1,4]);
		var ellipse_B = board.create('point', [-1,-4]);
		var ellipse_C = board.create('point', [1,1]);
		var ellipse_el = board.create('ellipse',[ellipse_A,ellipse_B,ellipse_C]);

	</script>


Complex Numbers
---------------------------------

Definition
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

:Euler formula:

:math:`e^{i\pi}=-1`

+--------------------------------------------+---------------------------------------------+
| :math:`\cos{x}=\frac{e^{ix}+e^{-ix}}{2}`   | :math:`\sin{x}=\frac{e^{ix}-e^{-ix}}{2i}`   |
+--------------------------------------------+---------------------------------------------+
| :math:`\cos{x}^2=\frac{cos(2x)+1}{2}`      | :math:`\sin{x}^2=\frac{1-cos(2x)}{2}`       |
+--------------------------------------------+---------------------------------------------+
| :math:`\cos{x}^3=\frac{cos(3x)+3cos(x)}{4}`| :math:`\sin{x}^3=\frac{3sin(x)-sin(3x)}{4}` |
+--------------------------------------------+---------------------------------------------+

.. admonition:: Linearizations Example

	:math:`cos(x)^2 = \left( \frac{e^{ix} + e^{-ix}}{2} \right)^2 \\ = \frac{(e^{ix})^2 + 2e^{ix}e^{-ix} + (e^{-ix})^2}{2^2} = \frac{e^{2ix}+2e^{ix}e^{-ix}+e^{-2ix}}{4} \\ = \frac{e^{2ix} + 2 + e^{-2ix}}{4} = \frac{2(\frac{e^{2ix} + e^{-2ix}}{2}) + 2}{4} \\ = \frac{2cos(2x)+2}{4} = \frac{cos(2x)+1}{2}`

	:math:`sin(x)^2 = \left( \frac{e^{ix} - e^{-ix}}{2i} \right)^2 \\ = \frac{(e^{ix})^2 - 2e^{ix}e^{-ix} + (e^{-ix})^2}{2^2 * i^2} = \frac{e^{2ix}-2e^{ix}e^{-ix}+e^{-2ix}}{-4} \\ = \frac{e^{2ix} - 2 + e^{-2ix}}{-4} = \frac{2(\frac{e^{2ix} + e^{-2ix}}{2}) - 2}{-4} \\ = \frac{2cos(2x)-2}{-4} = \frac{1-cos(2x)}{2}`

.. admonition:: Complex definition	

	:math:`\sqrt{i} = -1` and :math:`\frac{d}{dt} e^t = e^t` then :math:`\frac{d}{dt} e^{it} = i*e^{it}`

+--------------------+-----------+----------------+
| Complex number     | Real Part | Imaginary Part |
+--------------------+-----------+----------------+
| :math:`z = a + ib` | :math:`a` | :math:`ib`     |
+--------------------+-----------+----------------+

.. raw:: html
	
	<div id="complex_jxgbox" class="jxgbox" style="width:400px; height:400px;"></div>
	<script type="text/javascript">
	 	var board = JXG.JSXGraph.initBoard('complex_jxgbox', {boundingbox: [-1.5, 1.5, 1.5, -1.5], axis:true, pan: {enabled: false}, showCopyright:false, showNavigation:false})
	 	var p1 = board.create('point', [0.0, 0.0], { fixed:true, visible:true })
	    var p2 = board.create('point', [1.0, 0.0], { fixed:true, visible:false })
	    var c1 = board.create('circle', [p1, p2], { dash:1, strokeColor:'grey', strokeOpacity:0.6 })
	    var s1 = board.create('slider', [[-1.4,-1.2],[1.0,-1.2],[0,Math.PI/4,4*Math.PI]], {name:'t', snapWidth:0.01})
	    var p4 = board.create('point', [
	    	function(){return Math.cos(s1.Value())},
	    	function(){return Math.sin(s1.Value())}], 
	    	{name:'z = e^{it}', tracer:true})

	    var p5 = board.create('point', [
	    	function(){return Math.cos(s1.Value()) + Math.cos(s1.Value()+Math.PI/2)},
	    	function(){return Math.sin(s1.Value()) + Math.sin(s1.Value()+Math.PI/2)}],
	    	{name:'d/dt'})

	    var p6 = board.create('point', [function(){return Math.cos(s1.Value())}, 0.0], {name:'cos(t)', color:'grey'})
	    var p7 = board.create('point', [0.0, function(){return Math.sin(s1.Value())}], {name:'sin(t)', color:'grey'})

	    var l1 = board.create('segment', [p1, p4])
	    var l2 = board.create('segment', [p4, p5], {strokeColor:'grey', strokeOpacity:0.2 })

	    var l3 = board.create('segment', [p4, p6], {strokeColor:'grey', strokeOpacity:0.6, dash:1 })
	    var l4 = board.create('segment', [p4, p7], {strokeColor:'grey', strokeOpacity:0.6, dash:1 })

	    var a1 = board.create('angle', [p2, p1, p4], {radius:0.2, name:'t'})
	    var a2 = board.create('angle', [p5, p4, p1], {radius:0.1})

	    t0 = board.create('text', [1.1, 0.1, '0']);
	    t1 = board.create('text', [1.1, -0.1, '2 Pi']);
	    t2 = board.create('text', [0.0, 1.1, 'Pi/2']);
	    t3 = board.create('text', [-1.1, 0.0, 'Pi']);
	    t4 = board.create('text', [0.0, -1.1, '3 Pi/2']);

	</script>

+--------------+------------------------------------------------------------------------------------------------------------------------+
| **number**   | :math:`z = \frac{\sqrt{3}}{2} + \frac{1}{2} i`                                                                         |
+--------------+------------------------------------------------------------------------------------------------------------------------+
| **modulus**  | :math:`|z| = \frac{\sqrt{3}}{2}^2 + \frac{1}{2}^2 = 0.75 + 0.25 = 1`                                                   |
+--------------+------------------------------------------------------------------------------------------------------------------------+
| **argument** | :math:`arg(z) = \frac{\pi}{6}` :math:`(cos(\frac{\pi}{6})=\frac{\sqrt{3}}{2}`, :math:`sin(\frac{\pi}{6})=\frac{1}{2})` |
+--------------+------------------------------------------------------------------------------------------------------------------------+
| **trigo**    | :math:`z = mod*(cos(arg)+i*sin(arg)) = cos(\frac{\pi}{6}) + i*sin(\frac{\pi}{6})`                                      |
+--------------+------------------------------------------------------------------------------------------------------------------------+
| **polar**    | :math:`z = mod*e^{i*arg} = e^{i*\frac{\pi}{6}}`                                                                        |
+--------------+------------------------------------------------------------------------------------------------------------------------+
| **conjug**   | :math:`\overline{z} = \frac{\sqrt{3}}{2} + -\frac{1}{2} i`                                                             |
+--------------+------------------------------------------------------------------------------------------------------------------------+

Transformations
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

:Rotation:

* center :math:`\Omega(\omega)`
* angle :math:`\theta`

.. raw:: html
	
	<div id="rotation_jxgbox" class="jxgbox" style="width:400px; height:400px;"></div>
	<script type="text/javascript">
	 	var board = JXG.JSXGraph.initBoard('rotation_jxgbox', {boundingbox: [-1.5, 1.5, 1.5, -1.5], axis:true, pan: {enabled: false}, showCopyright:false, showNavigation:false})
	 	var p1 = board.create('point', [0.0, 0.0], { fixed:true, visible:true, name:"Ω(ω)", color:'blue' })
	    var p2 = board.create('point', [1.0, 0.0], { fixed:true, visible:true, name:"z1", color:'blue' })
	    var srotation1 = board.create('slider', [[-1.4,-1.2],[1.0,-1.2],[0.0,(2*Math.PI)/3,4*Math.PI]], {name:'θ', snapWidth:0.1})

	    var p3 = board.create('point', [
	    	function(){return Math.cos(srotation1.Value())},
	    	function(){return Math.sin(srotation1.Value())}], { fixed:true, visible:true, name:"z2", color:'red' })

	    var l1 = board.create('segment', [p1, p2], {strokeColor:'grey', strokeOpacity:0.6, dash:1 })
	    var l2 = board.create('segment', [p1, p3], {strokeColor:'grey', strokeOpacity:0.6, dash:1 })

	    var a1 = board.create('angle', [p2, p1, p3], {radius:0.2, name:'θ'})
	</script>

:Translation:
* vector :math:`u`

.. raw:: html
	
	<div id="translation_jxgbox" class="jxgbox" style="width:400px; height:400px;"></div>
	<script type="text/javascript">
	 	var board = JXG.JSXGraph.initBoard('translation_jxgbox', {boundingbox: [-1.5, 1.5, 1.5, -1.5], axis:true, pan: {enabled: false}, showCopyright:false, showNavigation:false})
	    var p1 = board.create('point', [0.3, -0.5], { fixed:true, visible:true, name:"z1", color:'blue' })
	    var svectorx = board.create('slider', [[-1.4,-1.2],[0.8,-1.2],[-1.4,0.3,1.4]], {name:'ux', snapWidth:0.05})
	    var svectory = board.create('slider', [[-1.4,-1.4],[0.8,-1.4],[-1.4,-0.2,1.4]], {name:'uy', snapWidth:0.05})

	    var p2 = board.create('point', [
	    	function(){return p1.X() + svectorx.Value()},
	    	function(){return p1.Y() + svectory.Value()}], { fixed:true, visible:true, name:"z2", color:'red' })

	    var l1 = board.create('segment', [p1, p2], {strokeColor:'red', strokeOpacity:0.6, name:'u' })
	</script>

:Homothety:
* center :math:`\Omega(\omega)`
* ratio :math:`k = \frac{kb}{ka}`

.. raw:: html
	
	<div id="homothety_jxgbox" class="jxgbox" style="width:400px; height:400px;"></div>
	<script type="text/javascript">
	 	var board = JXG.JSXGraph.initBoard('homothety_jxgbox', {boundingbox: [-1.5, 1.5, 1.5, -1.5], axis:true, pan: {enabled: false}, showCopyright:false, showNavigation:false})

	    var p1 = board.create('point', [0.0, 0.0], { fixed:true, visible:true, name:"Ω(ω)", color:'blue' })
	    var p2 = board.create('point', [0.8, 1.2], { fixed:true, visible:true, name:"z1", color:'blue' })
	    var sratio = board.create('slider', [[-1.4,-1.2],[1.0,-1.2],[-2.0,1.2,2.0]], {name:'k', snapWidth:0.05})

	    var p3 = board.create('point', [ function(){ return p2.X()*sratio.Value() }, function(){ return p2.Y()*sratio.Value()}], { fixed:true, visible:true, name:"z2", color:'red' })
	    var l1 = board.create('segment', [p1, p2], {strokeColor:'grey', strokeOpacity:0.6, dash:1 })
	    var l2 = board.create('segment', [p1, p3], {strokeColor:'red', strokeOpacity:0.6, dash:0 })
	</script>

:Similarity: 
* center :math:`\Omega(\omega)` (single invariant  point, resolve :math:`s(\omega)=\omega`)
* angle :math:`\theta = Arg(a)`
* ratio :math:`k = |a|`

**Rotation** of center :math:`\Omega(\omega)` and of angle :math:`\theta` then **Homothety** of center :math:`\Omega(\omega)` and of ration :math:`k`

.. raw:: html
	
	<div id="similarity_jxgbox" class="jxgbox" style="width:400px; height:400px;"></div>
	<script type="text/javascript">
	 	var board = JXG.JSXGraph.initBoard('similarity_jxgbox', {boundingbox: [-1.5, 1.5, 1.5, -1.5], axis:true, pan: {enabled: false}, showCopyright:false, showNavigation:false})

	    var p1 = board.create('point', [0.0, 0.0], { fixed:true, visible:true, name:"Ω(ω)", color:'blue' })
	    var p2 = board.create('point', [0.8, 1.2], { fixed:true, visible:true, name:"z1", color:'blue' })
	    var p4 = board.create('point', [1.0, 0.0], { fixed:true, visible:false })
	    var a2 = board.create('angle', [p2, p1, p4], {  visible:false })
	    var ssimratio = board.create('slider', [[-1.4,-1.2],[1.0,-1.2],[-2.0,0.5,2.0]], {name:'k', snapWidth:0.05})
	    var ssimrota = board.create('slider', [[-1.4,-1.4],[1.0,-1.4],[0.0,(2*Math.PI)/3,4*Math.PI]], {name:'θ', snapWidth:0.1})

	    var p3 = board.create('point', [ 
	    	function(){ 
	    		return Math.cos(ssimrota.Value()-a2.Value()) * p1.Dist(p2) * ssimratio.Value()
	    	}, 
	    	function(){ 
	    		return Math.sin(ssimrota.Value()-a2.Value()) * p1.Dist(p2) * ssimratio.Value()
	    	}], 
	    	{ fixed:true, visible:true, name:"z2", color:'red' })

	    var l1 = board.create('segment', [p1, p2], {strokeColor:'grey', strokeOpacity:0.6, dash:1 })
	    var l2 = board.create('segment', [p1, p3], {strokeColor:'red', strokeOpacity:0.6, dash:0 })
	   	var a1 = board.create('angle', [p2, p1, p3], {radius:0.2, name:'θ'})
	</script>

.. admonition:: Example

	**Similarity of** :math:`\left[ \begin{array}{l} s: \mathbb{C} \rightarrow \mathbb{C} \\ \quad z \rightarrow (1-i\sqrt{3})z + 2i \end{array} \right]`

	**1. Center:** :math:`s(\omega) = \omega \Leftrightarrow (1-i\sqrt{3})\omega + 2i = \omega \\ 
	\qquad \qquad \Leftrightarrow \omega-(i\sqrt{3})\omega + 2i = \omega \\
	\qquad \qquad \Leftrightarrow (i\sqrt{3}\omega - 2i = 0 \\
	\qquad \qquad \Leftrightarrow \omega = \frac{2i}{i\sqrt{3}} = 2` 

	**2. Ratio:** :math:`k=|1-i \sqrt{3}| = \sqrt{1^2 + (\sqrt{3})^2} = \sqrt{1+3} = 2`

	**3. Angle:** :math:`\theta = arg(1-i \sqrt{3}) = arg(2 * (\frac{1}{2} - i \frac{\sqrt{3}}{2})) = arg(2 * cos(-\frac{\pi}{3}) + i sin(-\frac{\pi}{3})) = 2e^{i* (-\frac{\pi}{3})}`

Matrices
---------------------------------

https://www.youtube.com/watch?v=rowWM-MijXU

Vectors
---------------------------------


Vector spaces
---------------------------------

Tensors
---------------------------------

https://www.youtube.com/watch?v=TvxmkZmBa-k

Quaternions
---------------------------------