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
  name  TEXT NOT NULL,
  phone TEXT,
  PRIMARY KEY(id)
);

CREATE TABLE matches (
  id INT NOT NULL AUTO_INCREMENT,
  human_id INT NOT NULL ,
  group_id INT NOT NULL ,
  FOREIGN KEY(human_id) REFERENCES phones(id),
  FOREIGN KEY(group_id) REFERENCES groups(id),
  PRIMARY KEY(id),
  CONSTRAINT note UNIQUE (human_id, group_id)
);

INSERT INTO groups (name) VALUES ('opens'), ('friends'), ('families');
INSERT INTO phones (surname, name, phone) VALUES ('Romanova', 'Polina', '8(952)-378-40-75'),
	('Potter', 'Garry', '854634'),
	('Groter', 'Tanya', '45275'),
	('Marshak', 'Samyil', '1674'),
	('Rot', 'Veronika', '76856');


INSERT INTO matches (human_id, group_id) VALUES (1,1), (2,1), (3,2), (1, 2);















