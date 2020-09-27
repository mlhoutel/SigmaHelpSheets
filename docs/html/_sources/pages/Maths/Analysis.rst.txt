============================
Maths - Analysis
============================

.. contents:: Table of Contents
	:local: 

Values
---------------------------------

.. _more e digits: https://www.math.utah.edu/~pa/math/e.html
.. _more pi digits: https://www.piday.org/million/
.. _more tau digits: https://sites.google.com/site/digitsoftau/home/first-500-digits
.. _more phi digits: https://nerdparadise.com/math/reference/phi10000
.. _more sqr digits: https://apod.nasa.gov/htmltest/gifcity/sqrt2.1mil

+----------------------+------------------------------------------------------------------------------------------------------------------------------+
| Euler number         | :math:`e \simeq` 2.71828 18284 59045 23536 02874 71352 66249 77572 47093 69995 95749 66967 62772 40766 `more e digits`_      |
+----------------------+------------------------------------------------------------------------------------------------------------------------------+
| Archimedes' constant | :math:`\pi \simeq` 3.14159 26535 89793 23846 26433 83279 50288 41971 69399 37510 58209 74944 59230 78164 `more pi digits`_   |
+----------------------+------------------------------------------------------------------------------------------------------------------------------+
| Tau as :math:`2\pi`  | :math:`\tau \simeq` 6.28318 53071 79586 47692 52867 66559 0057 68394 33879 87502 11641 94988 91846 15632 `more tau digits`_  |
+----------------------+------------------------------------------------------------------------------------------------------------------------------+
| Golden Ratio         | :math:`\varphi \simeq` 1.61803 39887 49894 84820 45868 34365 63811 77203 09179 80576 28621 35448 62270 `more phi digits`_    |
+----------------------+------------------------------------------------------------------------------------------------------------------------------+
| Pythagoras' constant | :math:`\sqrt 2 \simeq` 1.41421 35623 73095 04880 16887 24209 69807 85696 71875 37694 80731 76679 73799 `more sqr digits`_    |
+----------------------+------------------------------------------------------------------------------------------------------------------------------+

Variables and Functions
---------------------------------

Todo

Quadratic Function
---------------------------------

.. admonition:: Resolve the Quadratic Equation

	:math:`ax^2+bx+c=0 \Leftrightarrow \Delta=b^2-4ac`

+--------------------+--------------------------------------+------------------------------------------+
| :math:`\Delta > 0` | 2 solutions in :math:`\mathbb{R}`    | :math:`\frac{-b\pm\sqrt{\Delta}}{2a}`    |
+--------------------+--------------------------------------+------------------------------------------+
| :math:`\Delta = 0` | 1 solution in :math:`\mathbb{R}`     | :math:`\frac{-b}{2a}`                    |
+--------------------+--------------------------------------+------------------------------------------+
| :math:`\Delta < 0` | 2 solutions in :math:`\mathbb{C}`    | :math:`\frac{-b\pm i\sqrt{-\Delta}}{2a}` |
+--------------------+--------------------------------------+------------------------------------------+

.. raw:: html
	
	<div id="quadratic_jxgbox" class="jxgbox" style="width:400px; height:400px;"></div>
	<script type="text/javascript">
		var brd = JXG.JSXGraph.initBoard('quadratic_jxgbox', {boundingbox: [-10, 10, 10, -10], axis:true, pan: {enabled: false}, showCopyright:false, showNavigation:false})
	    var quadratic_a = brd.create('slider',[[2,-3],[7,-3],[-10,1,10]], {name:'a', snapWidth:0.1})
	    var quadratic_b = brd.create('slider',[[2,-5],[7,-5],[-10,0,10]], {name:'b', snapWidth:0.1})
	    var quadratic_c = brd.create('slider',[[2,-7],[7,-7],[-10,0,10]], {name:'c', snapWidth:0.1})
	    f = brd.create('functiongraph',[function(quadratic_x){ return quadratic_a.Value()*quadratic_x*quadratic_x + quadratic_b.Value()*quadratic_x + quadratic_c.Value(); }]);
	</script>


Remarkable Identities
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
+-----------------------------+
| :math:`(a+b)^2=a^2+2ab+b^2` |
+-----------------------------+
| :math:`(a-b)^2=a^2-2ab+b^2` |
+-----------------------------+
| :math:`a^2-b^2=(a-b)(a+b)`  |
+-----------------------------+

TEMP
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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

+-----------------+---------------------+--------------------------+--------------------------+--------------------------+--------------------------+
|:math:`\theta`   |:math:`0`            |:math:`\frac{\pi}{6}`     |:math:`\frac{\pi}{4}`     |:math:`\frac{\pi}{3}`     |:math:`\frac{\pi}{2}`     |
|:math:`(deg)`    |:math:`(0^\circ)`    |:math:`(30^\circ)`        |:math:`(45^\circ)`        |:math:`(60^\circ)`        |:math:`(90^\circ)`        |
+-----------------+---------------------+--------------------------+--------------------------+--------------------------+--------------------------+
|:math:`\cos`     |:math:`1`            |:math:`\frac{\sqrt{3}}{2}`|:math:`\frac{\sqrt{2}}{2}`|:math:`\frac{1}{2}`       |:math:`0`                 |
+-----------------+---------------------+--------------------------+--------------------------+--------------------------+--------------------------+
|:math:`\sin`     |:math:`0`            |:math:`\frac{1}{2}`       |:math:`\frac{\sqrt{2}}{2}`|:math:`\frac{\sqrt{3}}{2}`|:math:`1`                 |
+-----------------+---------------------+--------------------------+--------------------------+--------------------------+--------------------------+
|:math:`\tan`     |:math:`0`            |:math:`\frac{\sqrt{3}}{3}`|:math:`1`                 |:math:`\sqrt{3}`          |:math:`+\infty`           |
+-----------------+---------------------+--------------------------+--------------------------+--------------------------+--------------------------+

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

+-------------------------------------------+----------------------------------------------------------+-------------------------------------------+
| :math:`\cosh{x}=\frac{e^x+e^{-x}}{2}`     | :math:`\arccos(\cos{x})=x [0;\pi]`                       | :math:`\cos(\arccos{x})=x [-1;1]`         |
+-------------------------------------------+----------------------------------------------------------+-------------------------------------------+
| :math:`\sinh{x}=\frac{e^x-e^{-x}}{2}`     | :math:`\arcsin(\sin{x})=x [-\frac{\pi}{2};\frac{\pi}{2}]`| :math:`\sin(\arcsin{x})=x [-1;1]`         |
+-------------------------------------------+----------------------------------------------------------+-------------------------------------------+
| :math:`\tanh{x}=\frac{e^{2x}-1}{e^{2x}+1}`| :math:`\arctan(\tan{x})=x [-\frac{\pi}{2};\frac{\pi}{2}]`| :math:`\tan(\arctan{x})=x \mathbb{R}`     |
+-------------------------------------------+----------------------------------------------------------+-------------------------------------------+


hyperbolic cos and sin graph


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



Differential Equations
============================

Fractals
============================