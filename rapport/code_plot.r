setwd(dir = "~/Documents/gis4/pm/csource/rapport")
getwd()
data <- read.csv("./data.txt")
plot(data$nb_ville, data$temps, type="o", col="blue", pch="o", lty=1, ylab = "y")

points(data$nb_ville, data$rs_temps, col="dark green",pch="-")
lines(data$nb_ville, data$rs_temps, col="dark green", lty=2)


legend(4,3600,legend=c("exhaustif_temps", "recuit_simule_temps"), col=c("blue", "green"),
       pch=c("o","-"), lty=c(1,2))

