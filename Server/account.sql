ALTER TABLE `account`
ADD COLUMN `pin` char(4) DEFAULT '' AFTER `password`;