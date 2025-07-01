# Учебная практика "Бекенд на C++"

## Задание 1. Введение в Backend-разработку и Docker

1. Изучить основы клиент-серверной архитектуры
2. Подготовить среду разработки, установить необходимое ПО (компилятор C++, Docker)
3. Изучить что такое Docker и зачем он нужен.
4. Установить Docker, изучить основные команды (docker run, docker build, docker images, docker ps).
5. Ознакомиться с документацией Docker для начинающих.

## Задание 2. Создание и контейнеризация простого C++ приложения (cpp-hello-app)

1. Изучить Dockerfile: основные инструкции.
2. Написать Dockerfile для контейнеризации C++ приложения, собрать образ и запустить контейнер.

## Задание 3. Разработка REST API на C++ (cpp-simple-api)

1. Изучить принципы REST API.
2. Создать простое REST API приложение на C++ с использованием Dragon
3. Обновить Dockerfile для контейнеризации REST API приложения, собрать образ и запустить контейнер

## Задание 4. Создание эндпоинтов и контроллеров (cpp-hostname-app)

Выполнить разработку контроллера, который выполняет запрос и отправляет ответ по эндпоинту, заданному в индивидуальном варианте.

### Команды для проверки:

#### Сборка образа
```
docker build -t cpp-hostname-app .
```

#### Запуск контейнера
```
docker run -p 3000:3000 --rm cpp-hostname-app
```

#### Тестирование
```
curl http://localhost:3000/api/hostname
```
#### Должен вернуть: 
```{"hostname":"<container-id>"}```

## Задание 5.1. Основы Kubernetes (cpp-hostname-k8s)

1. Изучить что такое Kubernetes и как с ним работать.
2. Установить Minikube для локального развертывания кластера Kubernetes.
3. Изучить принципы создания и развертывания простого приложения в Kubernetes
4. Создать Kubernetes манифесты для развертывания Docker контейнеров с приложением и настройка сервиса
5. Изучить основы масштабирования в Kubernetes.
6. Настроить автоматическое масштабирование приложения.

### Команды для проверки:

#### Переключиться на docker-среду Minikube
```eval $(minikube docker-env)```

#### Собрать Docker-образ внутри Minikube
```docker build -t cpp-hostname-k8s:local .```

#### Проверить образ
```docker images | grep cpp-hostname-k8s```

#### Старт кластера (если ещё не запущен)
```minikube start --driver=docker```

#### Включение необходимых аддонов
```minikube addons enable metrics-server```
```minikube addons enable ingress```

#### Применяем конфигурацию манифеста (deployment, service, hpa)
```kubectl apply -f deployment.yaml```
```kubectl apply -f service.yaml```
```kubectl apply -f hpa.yaml```

#### Проверяем статус
```kubectl get pods -w```
```kubectl get services```
```kubectl get hpa```

#### Получить доступ к сервису
```minikube service drogon-service --url```
#### Пример вывода: 
http://192.168.49.2:32123

#### Тестируем приложение
```curl http://192.168.49.2:32123/api/hostname```
#### Пример ответа: 
```{"hostname":"cpp-hostname-k8s-7d5f8c9b6c-2xqvh"}```
