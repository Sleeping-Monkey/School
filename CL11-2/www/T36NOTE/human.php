<html>
	<head>
		<title> Человек </title>
		<meta charset='atf-8'/>
	</head>
	<body>	
	<?php
		include('data.php');
	?>
	<?php
		$id_p = $_GET['id'];
		foreach($humans[$id_p] as $key => $value)
			echo '<b>' . $key . ':' . '</b>' . $value . '<br>';
	?>
	</body>

</html>