<?php
function exec_query($query)	
{
	$link = @mysql_connect('localhost', 'root', '');
	if ($link === FALSE)
		die('������ ����������� � ����: ' . mysql_error());
	if (!mysql_select_db('cl11218', $link))
		die('������ ����������� � ��: ' . mysql_error());
	$res = mysql_query($query, $link);
	$tmp = array();
	while (($r = mysql_fetch_array($res, MYSQL_ASSOC)) !== FALSE)
		$tmp[] = $r;
	mysql_free_result($res);
	mysql_close($link);
	return $tmp; 	
}
