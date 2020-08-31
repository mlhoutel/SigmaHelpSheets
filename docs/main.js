function fadeOutEffect(fadeTarget) {
    var fadeEffect = setInterval(function () {
        if (!fadeTarget.style.opacity) {
            fadeTarget.style.opacity = 1;
        }
        if (fadeTarget.style.opacity > 0) {
            fadeTarget.style.opacity -= 0.01;
        } else {
            clearInterval(fadeEffect);
        }
    }, 10);
}

window.addEventListener("DOMContentLoaded", function(){

	setTimeout(function(){fadeOutEffect(document.querySelector('.loader'))}, 2500);
	setTimeout(function(){fadeOutEffect(document.querySelector('.loader-wrapper'))}, 3500);
})

