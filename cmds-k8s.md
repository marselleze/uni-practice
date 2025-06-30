# 1. Переключиться на docker-среду Minikube
```eval $(minikube docker-env)```

# 2. Собрать Docker-образ внутри Minikube
```docker build -t cpp-hostname-k8s:local .```

# 3. Проверить образ
```docker images | grep cpp-hostname-k8s```

# 4. Старт кластера (если ещё не запущен)
```minikube start --driver=docker```

# Включение необходимых аддонов
```minikube addons enable metrics-server  # Для HPA```
```minikube addons enable ingress         # Для доступа извне```

# 5. Применяем конфигурацию манифеста (deployment, service, hpa)
```kubectl apply -f deployment.yaml```
```kubectl apply -f service.yaml```
```kubectl apply -f hpa.yaml```

# 6. Проверяем статус
```kubectl get pods -w```
```kubectl get services```
```kubectl get hpa```

# 7. Получить доступ к сервису
```minikube service drogon-service --url```
# Пример вывода: http://192.168.49.2:32123

# 8. Тестируем приложение
```curl http://192.168.49.2:32123/api/hostname```
# Пример ответа: {"hostname":"cpp-hostname-k8s-7d5f8c9b6c-2xqvh"}
