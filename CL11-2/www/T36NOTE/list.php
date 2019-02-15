<html>
	<head>
		<title> База Данных </title>
		<meta charset='atf-8'/>
	</head>
	<body>	
	<?php
		include('data.php');

	function print_array($a)
	{
		if(!is_array($a))
		{
			echo "<td>" . $a . "</td>";
			return;
		} 
		foreach($a as $key => $value)
		{
			print_array($value);
		}
	}
	$surname = '';
	if (isset($_GET['surname']))
		$surname = $_GET['surname'];
	$name = '';
	if (isset($_GET['name']))
		$name = $_GET['name'];
	?>    
	<form action='list.php' method='get'>
		<br>
		Surname: <input type='text' name='surname' value='<?php echo $surname; ?>' />
		<br><br>
		Name: <input type='text' name='name' value='<?php echo $name; ?>' />
		<br><br>
		<input type='submit' value='Фильтровать' />
		<br>
	</form>
	<?php
	if ($surname == '' and $name == '')
		$query = 'SELECT * FROM phones';
	elseif ($surname == '')
		$query = "SELECT * FROM phones WHERE name LIKE '%" . $name . "%'";
	elseif ($name == '')
		$query = "SELECT * FROM phones WHERE surname LIKE '%" . $surname . "%'";
	else
		$query = "SELECT * FROM phones WHERE name LIKE '%" . $name . "%' AND surname LIKE " . "'%" . $surname . "%'";
	$phones = exec_query($query);
	?>
	<form action='test.php' method='get'>
	<table border="10px" cellspacing='2px'>
	<tr>
		<td> id </td>
		<td> Имя </td>
		<td> Фамилия </td>
		<td> Телефон </td>
		<td> Группы </td>
		<td> Редактировать </td>
		<td> Удалить </td>
	</tr>
	<?php
	foreach($phones as $key => $value)
	{	
		echo '<tr>';
		print_array($value);
		echo '<td>';
		echo '<a href="human.php?id=' . $key . '"' . ' ' . 'torget="_blank">' . $value['name'];            
		echo '</td>';
		echo '<td>';
		echo '</td>';
		echo '</tr>';
	}
	?>
	</table>
	<input type='submit' value='Удалить выбраных' />
	</form>                             
	</body>
</html>