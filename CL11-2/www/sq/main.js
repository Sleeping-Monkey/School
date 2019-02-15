window.onload = function() {
	var but = document.getElementById('button');
	but.onclick = function() {
		var a = document.getElementById('a').value,
				b = document.getElementById('b').value,
				c = document.getElementById('c').value;
		res = document.getElementById('result');
		var disc = b * b - 4 * a * c;
		if (disc < 0) {
			res.innerHTML = "first root:<br />("
			res.innerHTML += (-2 * b) + "+<i>i</i>" + Math.sqrt(-disc) + ") /" + 2*a + "<br />"
			res.innerHTML += "second root:<br />("
			res.innerHTML += (-2 * b) + "-<i>i</i>" + Math.sqrt(-disc) + ") /" + 2*a + "<br />";
		} else if (disc == 0) {
			res.innerHTML = "root:" + (-2 * b) / (2 * a) + "<br />";
		} else {
			res.innerHTML = "first root:<br />"
			res.innerHTML += ((-2 * b) + Math.sqrt(disc)) / (2*a) + "<br />"
			res.innerHTML += "second root:<br />"
			res.innerHTML += ((-2 * b) - Math.sqrt(disc)) / (2*a) + "<br />";
		}
	}
}	

		

				  