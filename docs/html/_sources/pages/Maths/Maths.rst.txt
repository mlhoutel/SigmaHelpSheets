============================
Maths
============================

.. contents:: Table of Contents
	:local: 

Basics
============================

Sets and Domains
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

+--------------------+-----------------------------+-----------------------------+--------------------------------------------------------------------------------------------------------------------------+
| :math:`\mathbb{C}` | *Complexs* (Real+Imaginary) | :math:`-5i, 5, i, 3+2i, 10i`|                                                                                                                          |
+--------------------+-----------------------------+-----------------------------+                                                                                                                          |
| :math:`\mathbb{R}` | *Reals* (All non imaginary) | :math:`-8.535, 9.76, \pi, e`| .. figure:: https://upload.wikimedia.org/wikipedia/commons/thumb/a/a0/NumberSetinC.svg/220px-NumberSetinC.svg.png        |
+--------------------+-----------------------------+-----------------------------+      :width: 300px                                                                                                       |
| :math:`\mathbb{Q}` | *Rationals* (Fractions)     | :math:`\frac{3}{7}, 0.65, 7`|      :align: center                                                                                                      |
+--------------------+-----------------------------+-----------------------------+                                                                                                                          |
| :math:`\mathbb{Z}` | *Integers* (Whole numbers ) | :math:`-53337, -5, 0, 7, 19`|      :math:`\mathbb{N}\subset\mathbb{Z}\subset\mathbb{Q}\subset\mathbb{R}\subset\mathbb{C}`                              |
+--------------------+-----------------------------+-----------------------------+                                                                                                                          |
| :math:`\mathbb{N}` |*Naturals* (Integer Positive)| :math:`0, 1, 42, 69, 420`   |                                                                                                                          |
+--------------------+-----------------------------+-----------------------------+--------------------------------------------------------------------------------------------------------------------------+


Injection
Surjection
Bijection 

Quadratic Function
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. admonition:: Resolve the Quadratic Equation

	:math:`ax^2+bx+c=0 \Leftrightarrow \Delta=b^2-4ac`

+--------------------+--------------------------------------+------------------------------------------+------------------------------------------------------------------------------------------+
| :math:`\Delta > 0` | 2 solutions in :math:`\mathbb{R}`    | :math:`\frac{-b\pm\sqrt{\Delta}}{2a}`    | .. raw:: html                                                                            |
+--------------------+--------------------------------------+------------------------------------------+                                                                                          |
| :math:`\Delta = 0` | 1 solution in :math:`\mathbb{R}`     | :math:`\frac{-b}{2a}`                    |     <div id="quadratic_jxgbox" class="jxgbox" style="width:400px; height:200px;"></div>  |
+--------------------+--------------------------------------+------------------------------------------+                                                                                          |
| :math:`\Delta < 0` | 2 solutions in :math:`\mathbb{C}`    | :math:`\frac{-b\pm i\sqrt{-\Delta}}{2a}` |                                                                                          |
+--------------------+--------------------------------------+------------------------------------------+------------------------------------------------------------------------------------------+

.. raw:: html
	
	<script type="text/javascript">
		var brd = JXG.JSXGraph.initBoard('quadratic_jxgbox', {boundingbox: [-10, 10, 10, -10], axis:true, pan: {enabled: false}, showCopyright:false, showNavigation:false})
	    var quadratic_a = brd.create('slider',[[2,-3],[7,-3],[-10,1,10]], {name:'a', snapWidth:0.1})
	    var quadratic_b = brd.create('slider',[[2,-5],[7,-5],[-10,0,10]], {name:'b', snapWidth:0.1})
	    var quadratic_c = brd.create('slider',[[2,-7],[7,-7],[-10,0,10]], {name:'c', snapWidth:0.1})
	    f = brd.create('functiongraph',[function(quadratic_x){ return quadratic_a.Value()*quadratic_x*quadratic_x + quadratic_b.Value()*quadratic_x + quadratic_c.Value(); }]);
	</script>

Sequences
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Triangle
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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

Remarkable Identities
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

:math:`(a+b)^2=a^2+2ab+b^2`

:math:`(a-b)^2=a^2-2ab+b^2`

:math:`a^2-b^2=(a-b)(a+b)`

+--------------------+------------------------------------------------------------------+----------------------------------+------------------------------------------------------------------------------------------+
|                    | - :math:`(e^x)' = e^x`                                           | - :math:`exp(ln(x))=x`           | .. raw:: html                                                                            |
| :math:`e^x`        | - :math:`\lim\limits_{\substack{x \to +\infty}} e^x = +\infty`   | - :math:`exp(0)=1`               |                                                                                          |
|                    | - :math:`\lim\limits_{\substack{x \to -\infty}} e^x = 0`         | - :math:`exp(1)=e=2.71828182846` |      <div id="exp_jxgbox" class="jxgbox" style="width:400px; height:200px;"></div>       |
+--------------------+------------------------------------------------------------------+----------------------------------+                                                                                          |
|                    | - :math:`(ln(x))' = \frac{1}{x}`                                 | - :math:`ln(exp(x))=x`           |                                                                                          |
| :math:`ln(x)`      | - :math:`\lim\limits_{\substack{x \to +\infty}} ln(x) = +\infty` | - :math:`ln(0)=undefined`        |                                                                                          |
|                    | - :math:`\lim\limits_{\substack{x \to 0}} ln(x) = -\infty`       | - :math:`ln(1)=0`                |                                                                                          |
+--------------------+------------------------------------------------------------------+----------------------------------+------------------------------------------------------------------------------------------+

.. raw:: html
	
	
	<script type="text/javascript">
		var brd = JXG.JSXGraph.initBoard('exp_jxgbox', {boundingbox: [-10, 10, 10, -10], axis:true, pan: {enabled: false}, showCopyright:false, showNavigation:false})
	    var exp = brd.create('functiongraph',[function(x){ return Math.exp(x); }],{strokecolor: 'red'});
	    exp.setLabel('f(x)=exp(x)')
	    exp.labelColor('red')

	    var line = brd.create('functiongraph',[function(x){ return x; }],{strokecolor: 'grey', dash:1});
	    line.setLabel('y=x')
	    line.labelColor('grey')

	    var log = brd.create('functiongraph',[function(x){ return Math.log(x); }],{strokecolor: 'blue'});
	    log.setLabel('g(x)=ln(x)')
	    log.labelColor('blue')
	</script>

Congruence
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

TODO

Trigonometry
============================

Cos, Sin, Tan
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

+-----------------+---------------------+--------------------------+--------------------------+--------------------------+--------------------------+-------------------------------------------------------------------------------------------+
|:math:`\theta`   |:math:`0`            |:math:`\frac{\pi}{6}`     |:math:`\frac{\pi}{4}`     |:math:`\frac{\pi}{3}`     |:math:`\frac{\pi}{2}`     |                                                                                           |
|:math:`(deg)`    |:math:`(0^\circ)`    |:math:`(30^\circ)`        |:math:`(45^\circ)`        |:math:`(60^\circ)`        |:math:`(90^\circ)`        | .. figure:: https://i.pinimg.com/originals/1d/89/0d/1d890d831b0f9b8e24124a7bc6a61afb.gif  |
+-----------------+---------------------+--------------------------+--------------------------+--------------------------+--------------------------+      :width: 300px                                                                        |
|:math:`\cos`     |:math:`1`            |:math:`\frac{\sqrt{3}}{2}`|:math:`\frac{\sqrt{2}}{2}`|:math:`\frac{1}{2}`       |:math:`0`                 |      :align: center                                                                       |
+-----------------+---------------------+--------------------------+--------------------------+--------------------------+--------------------------+                                                                                           |
|:math:`\sin`     |:math:`0`            |:math:`\frac{1}{2}`       |:math:`\frac{\sqrt{2}}{2}`|:math:`\frac{\sqrt{3}}{2}`|:math:`1`                 |      Trigonometrical circle                                                               |
+-----------------+---------------------+--------------------------+--------------------------+--------------------------+--------------------------+                                                                                           |
|:math:`\tan`     |:math:`0`            |:math:`\frac{\sqrt{3}}{3}`|:math:`1`                 |:math:`\sqrt{3}`          |:math:`+\infty`           |                                                                                           |
+-----------------+---------------------+--------------------------+--------------------------+--------------------------+--------------------------+-------------------------------------------------------------------------------------------+


:math:`\cos^2(x)+\sin^2(x)=1`

:math:`\cos(x+y)=\cos(x)*\cos(y) - \sin(x)*\sin(y)`

:math:`\sin(x+y)=\sin(x)*\cos(y) + \cos(x)*\sin(y)`

:math:`\cos^2(x) - \sin^2(x)=\cos(2x)`

:math:`\cos^2(x) = \frac{1+\cos(2x)}{2}`

Arccos, Arcsin, Arctan
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

+------------------------------------------------------+-----------------------------------------------------+----------------------------------+
| :math:`\arcsin{0}=0`                                 | :math:`\arccos{0}=\frac{\pi}{2}`                    | :math:`\arctan{0}=0`             |
+------------------------------------------------------+-----------------------------------------------------+----------------------------------+
| :math:`\arcsin{\frac{3\pi}{4}}=\frac{\pi}{4}`        | :math:`\arccos{-1}=\pi`                             | :math:`\arctan{1}=\frac{\pi}{4}` |
+------------------------------------------------------+-----------------------------------------------------+----------------------------------+
| :math:`\arcsin{-1}=-\frac{\pi}{2}`                   | :math:`\arccos{1}=0`                                |:math:`\arctan{-1}=-\frac{\pi}{4}`|
+------------------------------------------------------+-----------------------------------------------------+----------------------------------+
| :math:`\arcsin{\sin{\frac{15\pi}{4}}}=-\frac{\pi}{4}`| :math:`\arccos{\frac{-\sqrt{3}}{2}}=\frac{5\pi}{6}` |                                  |
+------------------------------------------------------+-----------------------------------------------------+----------------------------------+
| :math:`\arcsin{\frac{1}{2}}=\frac{\pi}{6}`           | :math:`\arccos{\frac{1}{2}}=\frac{\pi}{3}`          |                                  |
+------------------------------------------------------+-----------------------------------------------------+----------------------------------+

+------------------------------------------------------------------------------------+------------------------------------------------------------------------------------+------------------------------------------------------------------------------------+
| .. raw:: html                                                                      | .. raw:: html                                                                      | .. raw:: html                                                                      |
|                                                                                    |                                                                                    |                                                                                    |
|      <div id="cos_jxgbox" class="jxgbox" style="width:200px; height:200px;"></div> |      <div id="sin_jxgbox" class="jxgbox" style="width:200px; height:200px;"></div> |      <div id="tan_jxgbox" class="jxgbox" style="width:200px; height:200px;"></div> |
|                                                                                    |                                                                                    |                                                                                    |
+------------------------------------------------------------------------------------+------------------------------------------------------------------------------------+------------------------------------------------------------------------------------+

.. raw:: html
	
	<script type="text/javascript">
		var cos_board = JXG.JSXGraph.initBoard('cos_jxgbox', {boundingbox: [-1, Math.PI, Math.PI, -1], axis:true, pan: {enabled: false}, showCopyright:false, showNavigation:false})

	    var cos = cos_board.create('functiongraph',[function(x){ return Math.cos(x); }, 0, Math.PI],{strokecolor: 'red'});
	    cos.setLabel('cos')
	    cos.labelColor('red')

	    var cos_line = cos_board.create('functiongraph',[function(x){ return x; }, -1, Math.PI],{strokecolor: 'grey', dash:1});
	    cos_line.setLabel('y=x')
	    cos_line.labelColor('grey')

	    var arccos = cos_board.create('functiongraph',[function(x){ return Math.acos(x); }, -1, Math.PI],{strokecolor: 'blue'});
	    arccos.setLabel('arccos')
	    arccos.labelColor('blue')

	    var sin_board = JXG.JSXGraph.initBoard('sin_jxgbox', {boundingbox: [-Math.PI/2, Math.PI/2, Math.PI/2, -Math.PI/2], axis:true, pan: {enabled: false}, showCopyright:false, showNavigation:false})

	    var sin = sin_board.create('functiongraph',[function(x){ return Math.sin(x); }, -Math.PI/2, Math.PI/2],{strokecolor: 'red'});
	    sin.setLabel('sin')
	    sin.labelColor('red')

	    var sin_line = sin_board.create('functiongraph',[function(x){ return x; }, -Math.PI/2, Math.PI/2],{strokecolor: 'grey', dash:1});
	    sin_line.setLabel('y=x')
	    sin_line.labelColor('grey')

	    var arcsin = sin_board.create('functiongraph',[function(x){ return Math.asin(x); }, -Math.PI/2, Math.PI/2],{strokecolor: 'blue'});
	    arcsin.setLabel('arcsin')
	    arcsin.labelColor('blue')

	    var tan_board = JXG.JSXGraph.initBoard('tan_jxgbox', {boundingbox: [-3, 3, 3, -3], axis:true, pan: {enabled: false}, showCopyright:false, showNavigation:false})

	    var tan = tan_board.create('functiongraph',[function(x){ return Math.tan(x); }, -Math.PI/2, Math.PI/2],{strokecolor: 'red'});
	    tan.setLabel('tan')
	    tan.labelColor('red')

	    var cos_line = tan_board.create('functiongraph',[function(x){ return x; }, -3, 3],{strokecolor: 'grey', dash:1});
	    cos_line.setLabel('y=x')
	    cos_line.labelColor('grey')

	    var arctan = tan_board.create('functiongraph',[function(x){ return Math.atan(x); }, -3, 3],{strokecolor: 'blue'});
	    arctan.setLabel('arctan')
	    arctan.labelColor('blue')
	</script>

Hcos, Hsin, Htan
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

:math:`(\cosh+\sinh)(\cosh-\sinh)=1`

:math:`\cosh^2(x)=\sinh^2(x)=1`

:math:`\cosh(x)+\sinh(x)=e^x`

:math:`\cosh(x)-\sinh(x)=e^{-x}`

hyperbolic cos and sin graph

Complex numbers
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

:Euler formula:

:math:`e^{i\pi}=-1`

+------------------------------------------+-------------------------------------------+
| :math:`\cos{x}=\frac{e^{ix}+e^{-ix}}{2}` | :math:`\sin{x}=\frac{e^{ix}-e^{-ix}}{2i}` |
+------------------------------------------+-------------------------------------------+

To develop...


+-------------------------------------------+----------------------------------------------------------+-------------------------------------------+
| :math:`\cosh{x}=\frac{e^x+e^{-x}}{2}`     | :math:`\arccos(\cos{x})=x [0;\pi]`                       | :math:`\cos(\arccos{x})=x [-1;1]`         |
+-------------------------------------------+----------------------------------------------------------+-------------------------------------------+
| :math:`\sinh{x}=\frac{e^x-e^{-x}}{2}`     | :math:`\arcsin(\sin{x})=x [-\frac{\pi}{2};\frac{\pi}{2}]`| :math:`\sin(\arcsin{x})=x [-1;1]`         |
+-------------------------------------------+----------------------------------------------------------+-------------------------------------------+
| :math:`\tanh{x}=\frac{e^{2x}-1}{e^{2x}+1}`| :math:`\arctan(\tan{x})=x [-\frac{\pi}{2};\frac{\pi}{2}]`| :math:`\tan(\arctan{x})=x \mathbb{R}`     |
+-------------------------------------------+----------------------------------------------------------+-------------------------------------------+


Linearisation
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

+-------------------------------------------+-------------------------------------------+
| :math:`cos^2(x)=\frac{1-\cos{2x}}{2}`     | :math:`sin^2(x)=\frac{1-\cos{2x}}{2}`     |
+-------------------------------------------+-------------------------------------------+

To develop...


Integration
============================

:Derivatives:

+-----------------------------------------+----------------------------------------+----------------------------+
|             :math:`Function`            |            :math:`Derivative`          |       :math:`Domain`       |  
+=========================================+========================================+============================+
| :math:`a`                               | :math:`0`                              |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`ax`                              | :math:`a`                              |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`x^n`                             | :math:`nx^{n-1}`                       |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\frac{1}{x^n}`                   | :math:`-\frac{n}{x^{n+1}}`             |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\sqrt{x}`                        | :math:`\frac{1}{2 \sqrt{x}}`           |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\ln{x}`                          | :math:`\frac{1}{x}`                    |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`e^x`                             | :math:`e^x`                            |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\sin{x}`                         | :math:`\cos{x}`                        |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\cos{x}`                         | :math:`-\sin{x}`                       |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\tan{x}=\frac{\sin{x}}{\cos{x}}` | :math:`\frac{1}{\cos^2(x)}=1+\tan^2(x)`|                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\arcsin{x}`                      | :math:`\frac{1}{\sqrt{1-x^2}}`         |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\arccos{x}`                      | :math:`-\frac{1}{\sqrt{1-x^2}}`        |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\arctan{x}`                      | :math:`\frac{1}{\sqrt{1+x^2}}`         |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\sinh{x}`                        | :math:`\cosh{x}`                       |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\cosh{x}`                        | :math:`\sinh{x}`                       |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\tanh{x}`                        | :math:`\frac{1}{cosh^2(x)}`            |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`ku`                              | :math:`ku'`                            |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`u+v`                             | :math:`u'+v'`                          |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`uv`                              | :math:`u'v+uv'`                        |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\frac{u}{v}`                     | :math:`\frac{u'v-uv'}{v^2}`            |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`u^n`                             | :math:`nu'u^{n-1}`                     |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\sqrt{u}`                        | :math:`\frac{u'}{2\sqrt{u}}`           |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`e^u`                             | :math:`u'e^u`                          |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\ln{u}`                          | :math:`\frac{u'}{u}`                   |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\arctan{u}`                      | :math:`\frac{u'}{1+u^2}`               |                            |
+-----------------------------------------+----------------------------------------+----------------------------+

:Primitives:

+-----------------------------------------+----------------------------------------+----------------------------+
|         :math:`Function`                |             :math:`Primitive+C`        |       :math:`Domain`       |  
+=========================================+========================================+============================+
| :math:`x^n`                             | :math:`\frac{1}{n+1}x^{n+1}`           |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\frac{1}{x}`                     | :math:`\ln{x}`                         |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`u'e^u`                           | :math:`e^u`                            |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`u'u^n`                           | :math:`\frac{1}{n+1}u^{n+1}`           |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\frac{u'}{u}`                    | :math:`\ln{|u|}`                       |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\frac{1}{2\sqrt{x}}`             | :math:`\sqrt{x}`                       |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\frac{1}{\sqrt{1-u^2}}`          | :math:`\arcsin{u}`                     |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\frac{-1}{\sqrt{1-u^2}}`         | :math:`\arccos{u}`                     |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\frac{1}{1+u^2}`                 | :math:`\arctan{u}`                     |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`u'\cos{u}`                       | :math:`\sin{u}`                        |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`u'\sin{u}`                       | :math:`-\cos{u}`                       |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\frac{u'}{\cos^2(u)}`            | :math:`\tan{u}`                        |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\frac{-u'}{u^2}`                 | :math:`\frac{1}{u}`                    |                            |
+-----------------------------------------+----------------------------------------+----------------------------+
| :math:`\ln{x}`                          | :math:`x\ln{x}-x`                      |                            |
+-----------------------------------------+----------------------------------------+----------------------------+

Integration Help
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

:math:`x\sqrt{x} = x^{\frac{3}{2}}`

:math:`\frac{1}{x^2+2x+5} = \frac{1}{(x+\alpha)(x+\beta)} \Rightarrow \frac{a}{x+\alpha}+\frac{b}{x+\beta}`

:math:`\frac{1}{1+e^{-x}} = \frac{1+e^{-x}-e^{-x}}{1+e^{-x}}`

:math:`\mu = \frac{1}{b-a} \int_a^b f`

Parité:
:math:`f(-x)=f(x)` Paire
:math:`f(-x)=-f(x)` Impaire

Tangentes
:math:`f'(a)(x-a)+f(a)=y` 

:math:`\lim_{x \to a} \frac{f(x)-f(a)}{x-a} = f'(a)` 

ex: 
:math:`\lim_{x \to 0} \frac{\sin{x}}{x}=\frac{\sin{x}-\sin{0}}{x-0}=\sin'(0)=\cos(0)=1` 


:math:`(f \circ u)'(x)=u'(x)f(u(x))` 

:math:`f(x)=y \Leftrightarrow x=f^{-1}(y)` 

:math:`(f^{-1})'(y)=\frac{1}{f'(x)}` and :math:`y=f(x)`

Limits
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

limits in 0 

partie régulière (terme constant)
=> même limite
=> même signe

Si :math:`\frac{0}{0} \Rightarrow  x=1+h (ex en 1) puis h \rightarrow 0`

:math:`\lim\limits_{\substack{h \to 0}} ln(h) = h+\circ(h)`

:math:`\lim\limits_{\substack{h \to 0}} sin(h) = h+\circ(h)`

Integration by Parts
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. admonition:: Integration by Parts Formula

	:math:`\left\uparrow \begin{array}{l}
	A (arctan, arcsin, arccos) \\
	L (logarithm) \\
	P (polynomial) \\
	E (exponential) \\
	S (sin, cos, tan)
	\end{array}\right\} Priority (primitive)\quad Formula: \int_{a}^{b} fg' = \left[fg\right]_a^b - \int_{a}^{b} f'g`  

:Example:

:math:`\left. \begin{array}{l} xe^x \\ u v' \end{array}\right.
\left(\begin{array}{l} u=x \longrightarrow u'=1 \\v'=e^x \longrightarrow v=e^x\end{array}\right)`

:math:`\int_{a}^{b} uv'=\left[uv\right]_a^b-\int_{a}^{b} u'v \Leftrightarrow ...`

Integration by Change of Variables
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. admonition:: Integration by Change of Variables

	:math:`Formula: \int_{u(a)}^{u(b)} f(x) dx = \int_{a}^{b} f(u(t))u'(t) dt\quad` We changed variable by posing :math:`x=u(t)`

:Example:

:math:`\int_{0}^{1} \sqrt{1-t^2}dt` with :math:`t=\sin(x) \Leftrightarrow \left\{ \begin{array}{l} \frac{dt}{dx}=\cos(x) \\ dt=\cos(x) dx \end{array}\right. \left\{ \begin{array}{l} \sin{\frac{\pi}{2}}=1 \\ \sin{0}=0 \end{array}\right.`

:math:`\int_{0}^{\frac{\pi}{2}} \sqrt{1-\sin^2(x)\cos(x)dx} \Leftrightarrow \int_{0}^{\frac{\pi}{2}} |\cos(x)|\cos(x)dx`

:math:`Explanation: \sin^2(x)+\cos^2(x)=1 \Leftrightarrow |\cos(x)|=\sqrt{\sin^2(x)-1}`

:math:`\int_{0}^{\frac{\pi}{2}} |\cos(x)|\cos(x)dx \Leftrightarrow  \frac{1}{2}\left[\sin(2x)+x\right]_{0}^{\frac{\pi}{2}} = \frac{1}{2}(0+\frac{\pi}{2}-0-0)=\frac{\pi}{4}`

:math:`Explanation: cos^2(x)=(\frac{e^{ix}+e^{-ix}}{2})^2 = \frac{1}{4}(e^{2ix}+e^{-2ix}+2e^{ix}e^{-ix}) = \frac{1}{2}(\cos(2x)+1)`


Integrability and Comparison
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

+---------------------------------------------------------------------------------------------------+---------------------------------------+
| :math:`f=\underset{\alpha}{\bigcirc}(g)\frac{f}{g}=u \underset{\alpha}{\longmapsto} \mathbb{R}>1` |  f dominated by g                     |
+---------------------------------------------------------------------------------------------------+---------------------------------------+
| :math:`f=\underset{\alpha}{\circ}(g)\frac{f}{g}=u \underset{\alpha}{\longmapsto} 0`               |  f negligible in front of g           |
+---------------------------------------------------------------------------------------------------+---------------------------------------+
| :math:`f\underset{\alpha}{\sim}(g)\frac{f}{g}=u \underset{\alpha}{\longmapsto} 1`                 |  f similar to g                       |
+---------------------------------------------------------------------------------------------------+---------------------------------------+

:Convergence:

Geometrical sequence and :math:`|q|<1 \rightarrow \sum_{n=0}^{+\infty} q^n = \frac{1}{1-q}`

Real sequence with positive terms : divide by :math:`\frac{1}{n^2}` or by :math:`\frac{2^n}{1}`

Numerical sequence example:

:math:`un=\sqrt{n}-\sqrt{n-1} \Leftrightarrow \sum un =`

:math:`\left. \begin{array}{l} (\sqrt{1})-\sqrt{0} \\ (\sqrt{2})-(\sqrt{1}) \\ ... \\ \sqrt{n}-(\sqrt{n-1}) \end{array}\right. = \sqrt{n} \underset{n \to +\infty}{\longmapsto} +\infty`

:math:`f-g \underset{+\infty}{\longmapsto} 0 (asymptote)`

.. admonition:: Riemann (exponent)
	
	:math:`\sum \frac{1}{n^{\alpha}}` converges iff :math:`\alpha>1`

.. admonition:: Geometrical (reason) 
	
	:math:`\sum (r)^n` converges iff :math:`|r|<1`

Series
============================

:Factorials:

.. admonition:: Factorial Formula
	
	:math:`n! = \prod\limits_{1 \leq i \leq n} i = 1 \times 2 \times 3 \times 4 \times ... \times (n-1) \times n`

+----------+---------+---------+----------+----------+-----------+------------+------------+--------------+---------------+
|:math:`n` |:math:`0`|:math:`1`|:math:`2` | :math:`3`| :math:`4` | :math:`5`  | :math:`6`  | :math:`7`    | :math:`8`     |
+----------+---------+---------+----------+----------+-----------+------------+------------+--------------+---------------+
|:math:`n!`|:math:`1`|:math:`1`|:math:`2` | :math:`6`| :math:`24`| :math:`120`| :math:`720`| :math:`5040` | :math:`40320` |
+----------+---------+---------+----------+----------+-----------+------------+------------+--------------+---------------+

Taylor Series
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

:math:`e^x = \sum\limits_{n=0}^{+\infty} \frac{x^n}{n!} = 1+\frac{x}{1!}+\frac{x^2}{2!}+\frac{x^3}{3!}+...+\frac{x^n}{n!}+\circ(x^n)`

:math:`\frac{1}{1-x} = \sum\limits_{n=0}^{+\infty} x^n = 1+x+x^2+x^3+...+x^n+\circ(x^n)`

:math:`\ln(1+x) = \sum\limits_{n=1}^{+\infty} \frac{(-1)^{n+1}}{n}x^n = x-\frac{x^2}{2}+\frac{x^3}{3}-...+(-1)^{n-1}\frac{x^n}{n}+\circ(x^n)`

:math:`\sin(x) = \sum\limits_{n=0}^{+\infty} \frac{(-1)^n}{(2n+1)!}x^{2n+1} = x-\frac{x^3}{3!}+\frac{x^5}{5!}-...+(-1)^n\frac{x^{2n+1}}{(2n)!}+\circ(x^{2n+1})`

:math:`\cos(x) \sum\limits_{n=0}^{+\infty} \frac{(-1)^n}{(2n)!}x^{2n} = 1-\frac{x^2}{2!}+\frac{x^4}{4!}-...+(-1)^n\frac{x^{2n}}{(2n)!}+\circ(x^{2n})`

:math:`(1+x)^\alpha = 1+\sum\limits_{n=1}^{+\infty} \binom{\alpha}{n}x^n = 1+\frac{\alpha}{1!}x+\frac{\alpha(\alpha-1)}{2!}x^2+\frac{\alpha(\alpha-1)(\alpha-2}{3!}x^3+...+\frac{\alpha(\alpha-1)...(\alpha-n+1)}{n!}x^n+\circ(x^{n})`

:Overfittingt and Underfitting:

.. figure:: https://miro.medium.com/max/2250/1*6vPGzBNppqMHllg1o_se8Q.png

.. raw:: html
	
	<div id="regression_jxgbox" class="jxgbox" style="width:800px; height:400px;"></div>
	<script type="text/javascript">
		board = JXG.JSXGraph.initBoard('regression_jxgbox', {boundingbox:[-2, 100, 220, -70], grid: false ,axis:true, pan: {enabled: false}, showCopyright:false, showNavigation:false, showFullscreen:true});

		board.suspendUpdate();
		var pointlist = [];
		var degree = board.create('slider',[[10,90],[100,90],[1,1,30]],{name:'degree', snapWidth:1});     
		var number = board.create('slider',[[10,80],[100,80],[3,10,30]],{name:'number', snapWidth:1});     
		
		for (i=0; i<number.Value();i++) { pointlist.push(board.create('point', [200*Math.random() , 30*Math.random()+20 ], { style:4, strokecolor:"blue", name:" "})); }
		board.unsuspendUpdate();

		var regression = JXG.Math.Numerics.regressionPolynomial(degree, pointlist); 
		var reg = board.create('functiongraph',[regression],{strokeColor:'red'});

		var t = board.create('text',[20,-40, function(){ return "r(x) = " + regression.getTerm();} ],{strokeColor:'black',fontSize:'14px'});

		number.on('drag', function() { numberPoints(); });

		function numberPoints() {
			board.suspendUpdate();

			if (!(number.Value() == 2 && degree.Value() >= 1)) {
				for (i=0; i<pointlist.length; i++){ board.removeObject(pointlist[i]) }
				pointlist = [];

				for (i=0; i<number.Value();i++) { pointlist.push(board.create('point', [200*Math.random() , 30*Math.random()+20 ], { style:4, strokecolor:"blue", name:" "})); }
			
				regression = JXG.Math.Numerics.regressionPolynomial(degree, pointlist);
				board.removeObject(reg)
				reg = board.create('functiongraph',[regression],{strokeColor:'red'});
			}

			board.unsuspendUpdate();
		}
	</script>

Fourier Series
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. admonition:: Fourier coefficients Formula

	:math:`\left. \begin{array}{l}
	an=\frac{2}{T}\int_{0}^{T} f(t)\cos(\frac{2\pi}{T}n^t)dt \\
	bn=\frac{2}{T}\int_{0}^{T} f(t)\sin(\frac{2\pi}{T}n^t)dt
	\end{array}\right\} n \geqslant 1`

.. figure:: https://upload.wikimedia.org/wikipedia/commons/thumb/2/2c/Fourier_Series.svg/220px-Fourier_Series.svg.png

:Fourier Transform:


Probability
============================

.. admonition:: Conditional probability

	:math:`\mathit{P}_{B}(A)`: Probability of A knowing B

:math:`\mathit{P}_{B}(A)=\frac{P(A \cap B)}{P(B)} \Leftrightarrow P(A \cap B) = \mathit{P}_{B}(A) \times P(B) = \mathit{P}_{A}(B) \times P(A)`

:math:`Independence \Rightarrow P(A \cap B) = P(A) \times P(B)`

Discrete Variable
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
+------------------------------------------------+------------------------------------------------+------------------------------------------------+
| :math:`E(X)=\sum_{i=1}^{n}[xi \times P(xi)]`   | :math:`V(X)=\sum_{i=1}^{n}[xi-E(X)]^2`         | :math:`\sigma(X)=\sqrt{V(X)}`                  |
+------------------------------------------------+------------------------------------------------+------------------------------------------------+

:Bernouilli:

.. admonition:: Bernouilli Formula

	:math:`P(X=k)=C_k^n \times P(A)^k \times (1-P(A))^{n-k}`


We have two exclusive values, success :math:`A` (favorable) and failure :math:`\overline{A}`, with the probabilities :math:`P(A)=p` and :math:`P(\overline{A})=q`. The experiment is repeated n times in an identical and independent manner, with X the number of successes.

According to the statement [...], X therefore follows a binomial distribution of parameters p = ... and n = ...

+------------------------------------------------+------------------------------------------------+------------------------------------------------+
| :math:`E(X)=np`                                | :math:`V(X)=npq`                               | :math:`\sigma(X)=\sqrt{V(X)}`                  |
+------------------------------------------------+------------------------------------------------+------------------------------------------------+

:Exemple, We Roll 3 dice. What is the chance to have 2 times the 1?:

:math:`B(3;\frac{1}{6}), P(X=2)=C_3^2 \times \frac{1}{6}^2 \times \frac{5}{6}^{1}=0.0694`

:Poisson:

.. admonition:: Poisson Formula

	:math:`P(k)=P(X=k)=e^{-\lambda} \times \frac{\lambda^k}{k!}`

+------------------------------------------------+------------------------------------------------+------------------------------------------------+
| :math:`E(X)=\lambda`                           | :math:`V(X)=\lambda`                           | :math:`\sigma(X)=\sqrt{V(X)}`                  |
+------------------------------------------------+------------------------------------------------+------------------------------------------------+

:Exemple, one more person every 40 seconds. What is the chance to have 4 persons in 2 minutes?:

:math:`dt=40s, T=2 \times 60=120s, n=\frac{T}{dt}=\frac{120}{40}=3(expectation)`
:math:`\lambda=p \times n = 1 \times 3, P(X=4)=e^{-3} \times \frac{3^4}{3!}=0.168`

Continuous Variable
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

:Exponential:

.. admonition:: Exponential Formula

	:math:`P(0 \geq X \geq x)=1-e^{-\lambda x}\\P(X\leq x)=e^{-\lambda x}`

+------------------------------------------------+------------------------------------------------+------------------------------------------------+
| :math:`E(X)=\frac{1}{\lambda}`                 | :math:`V(X)=\frac{1}{\lambda^2}`               | :math:`\sigma(X)=\frac{1}{\lambda}`            |
+------------------------------------------------+------------------------------------------------+------------------------------------------------+

:Exemple, Lambda=6.116x10^(-4), Probability that T > 1000?:

:math:`P(T>1000)=1-P(T \leqslant 1000)=e^(-\lambda \times 1000)=0.542`

:Uniform:

.. admonition:: Reduced Centered Uniform Formula

	:math:`f(t)=\frac{1}{b-a}` if :math:`(t \in [a,b])`, else :math:`0`

+------------------------------------------------+------------------------------------------------+------------------------------------------------+
| :math:`E(X)=\frac{a+b}{2}`                     | :math:`V(X)=\frac{(b-a)^2}{12}`                | :math:`\sigma(X)=\sqrt{V(X)}`                  |
+------------------------------------------------+------------------------------------------------+------------------------------------------------+

:Reduced Centered Normal:

.. admonition:: Normal Formula

	:math:`T=\frac{X-m}{\sigma} N(0,1)`

+-----------+------+------+------+
|           | 95%  | 98%  | 99%  |
+-----------+------+------+------+
|           | 1.96 | 2.33 | 2.58 |
+-----------+------+------+------+

:math:`f(t)=\frac{1}{\sqrt{2\pi}} \times e^{-\frac{t^2}{2}}`

:math:`\prod(t)=P(T<t)=\int_{-\infty}^{t} (\frac{1}{2\pi} \times e^{-\frac{t^2}{2}})dt`


Comparison
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

:Expectation:

:math:`X=320`, observated :math:`\overline{X}=324`, :math:`\sigma(X)=3` and :math:`N=100`

:math:`Z=\frac{\mu - \overline{\lambda}}{\frac{\sigma(X)}{\sqrt{n}}}=-13.3, |Z|>1.96 (significative)`

:Exemple, A=N(1030,5)n1=10 and B=N(995,7)n2=20:

:math:`Z=\frac{1030-995}{\sqrt{\frac{5^2}{10}+\frac{7^2}{20}}}=15.7 \geqslant 1.96 (5\%)`

Approximation
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

:Binomial by Normal:

.. admonition:: Binomial Formula

	:math:`T=\frac{X-np}{\sqrt{npq}}`

+------------------------------------------------+------------------------------------------------+------------------------------------------------+
| :math:`E(Y)=np`                                | :math:`V(X)=npq`                               | :math:`\sigma(Y)=\sqrt{V(X)}`                  |
+------------------------------------------------+------------------------------------------------+------------------------------------------------+

:Binomial by Poisson:

.. admonition:: Poisson Formula

	:math:`\lambda=np` :math:`(n \geqslant 30, p \leqslant 0.10, np \leqslant 5)`

+------------------------------------------------+------------------------------------------------+------------------------------------------------+
| :math:`E(X)=\lambda`                           | :math:`V(X)=\lambda`                           | :math:`\sigma(X)=\sqrt{V(X)}`                  |
+------------------------------------------------+------------------------------------------------+------------------------------------------------+

:Poisson by Normal:

.. admonition:: Normal Formula

	:math:`T=\frac{X-\lambda}{\sqrt{\lambda}}`

+------------------------------------------------+------------------------------------------------+------------------------------------------------+
| :math:`E(X)=\lambda`                           | :math:`V(X)=\lambda`                           | :math:`\sigma(X)=\sqrt(\lambda)`               |
+------------------------------------------------+------------------------------------------------+------------------------------------------------+


Distribution
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. admonition:: Normal Median

	:math:`\overline{X} \Rightarrow N(\mu, \frac{\sigma}{\sqrt{n}})` for an infinite population, else :math:`m=\frac{\sigma}{\sqrt{n}} \times \sqrt{\frac{N-n}{N-1}}`

:Exemple, 5 machines, 500g packages with sigma=5g and 20 packages collected per machine. What is the probability of 499g or under?:

:math:`(\mu=500, \sigma=5) \Rightarrow N(500, \frac{5}{\sqrt{20 \times 5}})`

:math:`T=\frac{X-n}{\sigma}=\frac{499-500}{0.5}=-2 \Leftrightarrow P(X \leqslant 499)=2.28`

.. admonition:: Sample Proportion

	:math:`F(p, \sqrt{\frac{pq}{n}}` for :math:`n \geqslant 30`

:Exemple, 1% defective and 5000 pieces collected, certitude if < 1.2% ?:

:math:`\sigma=\sqrt{\frac{0.01 \times 0.99}{5000}} = 0.0014 \Rightarrow N(0.01, 0.0014)`

:math:`P(f<1.2)=P(T<\frac{0.012-0.01}{0.0014})=P(T<1.42)=92.22\%`


Average Estimation
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. admonition:: Ponctual Estimation

	:math:`X(\mu=?, \sigma=?) \Rightarrow` sample of size n :math:`(\mu e, \sigma e)`

	:math:`m=\mu e, s=\sqrt{\frac{n}{n-1}}\sigma e`

:Exemple, 13L/day for 21 days, sigma=2L. What would be an average estimation?:

:math:`m=13, s=\sqrt{\frac{21}{20}} \times 2 = 2.049`

.. admonition:: Confidence Interval 

	confidence coefficient = :math:`\alpha`, degree of freedom(khi2) = :math:`\chi^2=\frac{(sample-effective)^2}{effective}`

	+---------------------------+-------------------------------------------------------------------------------------------------------------------------------------------+
	|                           | Central Limit :math:`\Rightarrow` Normal Law :math:`(m, \frac{\sigma}{\sqrt{n}})`                                                         |
	| if :math:`n \geqslant 30` |                                                                                                                                           |
	|                           | :math:`P(m \in (a,b))=P(\overline{X}-t \times \frac{\sigma}{\sqrt{n}} < m < \overline{X}+t \times \frac{\sigma}{\sqrt{n}})=\alpha`        |
	+---------------------------+-------------------------------------------------------------------------------------------------------------------------------------------+
	|                           | Read Table :math:`\Rightarrow` Student Fisher                                                                                             |
	| if :math:`n < 30`         |                                                                                                                                           |
	|                           | :math:`P(m \in (a,b))=P(\overline{X}-t \times \frac{s}{\sqrt{n}} < m < \overline{X}+t \times \frac{s}{\sqrt{n}})=\alpha`                  |
	+---------------------------+-------------------------------------------------------------------------------------------------------------------------------------------+

Proportion Estimation
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. admonition:: Ponctual Estimation
	
	:math:`\sigma(D)=\sqrt{\frac{\sigma 1}{n1}^2 + \frac{\sigma 2}{n2}^2}`

	:math:`N(p,\sqrt{\frac{pq}{n}}) \Rightarrow f=pe \times \sigma p = \sqrt{\frac{n}{n-1}} \sigma e`

	+---------------------------+-------------------------------------------------------------------------------------------------------------------------------------------+
	| if :math:`n \geqslant 30` | :math:`\sigma p = \sqrt{\frac{pe(1-pe)}{n}}`                                                                                              |
	+---------------------------+-------------------------------------------------------------------------------------------------------------------------------------------+
	| if :math:`n < 30`         | :math:`\sigma p = \sqrt{\frac{pe(1-pe)}{n-1}}`                                                                                            |
	+---------------------------+-------------------------------------------------------------------------------------------------------------------------------------------+

:Exemple, We have a survey with a sample of 160 persons, 40 agree. What is the estimated proportion?:

:math:`N(\frac{1}{4}, \sqrt{\frac{\frac{1}{4} \times \frac{3}{4}}{160}})=N(0.25, 0.03423)`


Confidence Interval
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. admonition:: Confidence Interval

	:math:`P(p \in (a,b))=P(f-t \sqrt{\frac{f(1-f)}{n}} < p < f+t \sqrt{\frac{f(1-f)}{n}}) = \alpha`

	:math:`\sigma(X)=\sqrt{V(\overline{X})}, \sigma(\overline{X})=\frac{\sigma(X)}{\sqrt{N}} \Rightarrow \mu e = [E(\overline{X}) \pm 1.96 \times \sigma(\overline{X})]`

:Exemple, We have 64 clients, with an average of 60min, sigma=9.27. What would be an confidence interval at 5% ?:

:math:`\sigma(\overline{X})=\frac{9.27}{\sqrt{64}}=1.159 \Rightarrow \mu e = [60-1.96 \times 1.159; 60+1.96 \times 1.159]`

Vectors
============================

Tensors
============================

https://www.youtube.com/watch?v=TvxmkZmBa-k

Matrix
============================

https://www.youtube.com/watch?v=rowWM-MijXU

Quaternions
============================

Differential Equations
============================

Fractals
============================

Latex
============================

https://openclassrooms.com/fr/courses/1617396-redigez-des-documents-de-qualite-avec-latex/1621260-les-caracteres-speciaux

https://www.overleaf.com/learn/latex/List_of_Greek_letters_and_math_symbols
