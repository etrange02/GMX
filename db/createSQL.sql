--==============================================================
-- Nom de SGBD :  ANSI Level 2
-- Date de création :  24/07/2016 17:44:56
--==============================================================

--==============================================================
-- Table : ALPHABEAT
--==============================================================
create table ALPHABEAT (
ID                   INTEGER              not null,
LETTERS              VARCHAR(512)         not null,
primary key (ID)
);

--==============================================================
-- Table : THESAURUS
--==============================================================
create table THESAURUS (
ID                   INTEGER              not null,
ALPHABEAT_ID         INTEGER              not null,
WORD                 VARCHAR(254)         not null,
primary key (ID),
foreign key (ALPHABEAT_ID)
      references ALPHABEAT (ID)
);

--==============================================================
-- Table : VALUEDSET
--==============================================================
create table VALUEDSET (
ID                   INTEGER              not null,
ALPHABEAT_ID         INTEGER              not null,
NAME                 VARCHAR(128)         not null,
primary key (ID),
foreign key (ALPHABEAT_ID)
      references ALPHABEAT (ID)
);

--==============================================================
-- Table : GUEMATRIX
--==============================================================
create table GUEMATRIX (
ID                   INTEGER              not null,
VALUEDSET_ID         INTEGER              not null,
THESAURUS_ID         INTEGER              not null,
VALUE                INTEGER              not null,
OCCURENCE            INTEGER              not null default 1 
      check (OCCURENCE >= 1),
primary key (ID),
foreign key (THESAURUS_ID)
      references THESAURUS (ID),
foreign key (VALUEDSET_ID)
      references VALUEDSET (ID)
);

--==============================================================
-- Table : VALUEDLETTERS
--==============================================================
create table VALUEDLETTERS (
ID                   INTEGER              not null,
VALUEDSET_ID         INTEGER              not null,
LETTER               CHAR                 not null,
VALUE                INTEGER              not null,
primary key (ID),
foreign key (VALUEDSET_ID)
      references VALUEDSET (ID)
);

