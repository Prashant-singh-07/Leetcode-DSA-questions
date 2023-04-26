/* Write your T-SQL query statement below */
SELECT pa.firstName,pa.lastName,ad.city,ad.state FROM Person as pa LEFT JOIN Address as ad ON pa.personId = ad.personId;