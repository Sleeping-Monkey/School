<html>
	<head>
		<title> ������� ��������� </title>
		<meta charset='atf-8'/>
	</head>
	<body>    
		<form action='multable.php' method='GET'>
			<br /> ������� ���� ������������ ����� <br /> <br /> 
			<input type='text' name='max_x' /> <br />
			<br /> ������� ������ ������������ ����� <br /> <br />
			<input type='text' name='max_y' /> <br /> <br />
			<input type='submit' value='���������!' />
		</form>
			<table border='10px' cellspacing='5px'>
		<?php	
				for ($x = 1; $x <= $_GET['max_x']; $x++)
				{
					echo '<tr>';
					for ($y = 1; $y <= $_GET['max_y']; $y++)
						echo '<td><t1>' .  ' ' . $x * $y . ' ' . '</t1></td>';
					echo '</tr>';
				}	
		?>
			</table>
	</body>
</html>