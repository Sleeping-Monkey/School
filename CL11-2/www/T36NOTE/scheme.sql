DROP DATABASE IF EXISTS cl11218;
CREATE DATABASE cl11218;
USE cl11218;

CREATE TABLE groups (
	id INT NOT NULL AUTO_INCREMENT,
	name TEXT NOT NULL,
	PRIMARY KEY(id)
);

CREATE TABLE phones (
	id INT NOT NULL AUTO_INCREMENT,
	surname TEXT NOT NULL,
	name TEXT NOT NULL,
	phone TEXT NOT NULL,
	group_id INT NOT NULL DEFAULT 1,
	PRIMARY KEY(id),
	FOREIGN KEY(group_id) REFERENCES groups(id)
);

INSERT INTO groups (name) VALUES ('opens'), ('friends'), ('families');
INSERT INTO phones (surname, name, phone) VALUES ('Romanova', 'Polina', '8(952)-378-40-75'),
	('Potter', 'Garry', '854634'),
	('Groter', 'Tanya', '45275'),
	('Marshak', 'Samyil', '1674'),
	('Rot', 'Veronika', '76856');

SELECT * FROM groups;
SELECT * FROM phones;
 


  