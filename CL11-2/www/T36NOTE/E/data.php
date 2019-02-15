<?php
function exec_query($query)
{
  $dblink = mysql_connect('localhost', 'root', '');
  if ($dblink === FALSE)
    die ('Unable to connect to DBMS'.mysql_error());
  if (mysql_select_db('cl11218',$dblink) === FALSE)
    die("Database not exists");
  $res = mysql_query($query, $dblink);
  if ($res === FALSE)
    die("Illegal instruction ".mysql_error());
  return mysql_insert_id($dblink);
  mysql_close ($dblink);
}

function exec_tabl_query($query)
{
  $dblink = mysql_connect('localhost', 'root', '');
  if ($dblink === FALSE)
    die ('Unable to connect to DBMS'.mysql_error());
  if (mysql_select_db('cl11218',$dblink) === FALSE)
    die("Database not exists");

  $res = mysql_query($query, $dblink);
  if ($res === FALSE)
    die("Illegal instruction".mysql_error());
  
  $table = array();
  while (($r = mysql_fetch_array($res, MYSQL_ASSOC)) !== FALSE)
  {
    $table[] = $r;
  }
  
  mysql_free_result($res);
  mysql_close ($dblink);
  return $table;
}

function get_humans()
{
  $select = "SELECT * FROM phones;";
  $humans = exec_tabl_query($select);
  return $humans;
}
function get_human($id)
{
  $select = "SELECT * FROM phones WHERE id=".$id.";";
  $human = exec_tabl_query($select);
  return $human;
}

function get_groups()
{
  $sel = "SELECT * FROM groups";
  $groups = exec_tabl_query($sel);
  return $groups;
}

?>