library(dplyr)
library(ggplot2)
library(tidyr)

file_path <- "Titanic_train.csv"
data <- read.csv(file_path)
Summary_Stats <- summary(data)
print(Summary_Stats)

print(ggplot(data, aes(x = Age)) + geom_histogram(binwidth = 5, fill = "blue", color = "black") + labs(title = "Distribution of Age on Titanic", x = "Age", y = "Frequency"))

missing_values <- colSums(is.na(data))
print(missing_values)

data_distinct <- distinct(data)

data$Age[is.na(data$Age)] <- mean(data$Age, na.rm = TRUE)

missing_values <- colSums(is.na(data))
print(missing_values)

adult_passengers <- filter(data, Age > 18)
print(adult_passengers)

Sorted_titanic <- arrange(data, desc(Fare))
print(Sorted_titanic)


A <- data.frame(
  PassengerId = c(1, 2, 5),
  Fare.y = c(220.00, 221.00, 500.00)
)

print(colnames(data))
print(colnames(A))

merged_data <- merge(data, A, by.x = "PassengerId", by.y = "PassengerId")
print(merged_data)

print(ggplot(data, aes(x = Age, fill = factor(Survived, levels = c(0, 1)))) +
  geom_histogram(binwidth = 5, color = "black") +
  labs(
    title = "Age vs Survived",
    x = "Age", y = "Survival count",
    fill = "Survived"
  ) +
  scale_fill_manual(values = c("0" = "red", "1" = "blue")))

t_test_result <- t.test(Age ~ Survived, data = data)
print(t_test_result)

correlation_coefficient <- cor(data$Age, data$Fare)
print(correlation_coefficient)

print(ggplot(data, aes(x = factor(Survived), fill = factor(Survived))) +
  geom_bar() +
  labs(
    title = "Number of survivors on Titanic",
    x = "Survived", y = "Count"
  ) +
  scale_fill_manual(values = c("red", "green")))