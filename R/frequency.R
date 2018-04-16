library(MASS) 
school <- painters$School
school.freq <- table(school)

school.names <- list(A="Renaissance", B="Mannerist", C="Seicento", D="Venetian", E="Lombard", F="Sixteenth Century",
                     G="Seventeenth Century", H="French")

tab <- tab.disjonctif(school)