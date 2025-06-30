# Сборка образа
```
docker build -t cpp-hostname-app .
```

# Запуск контейнера
```
docker run -p 3000:3000 --rm cpp-hostname-app
```

# Тестирование
```
curl http://localhost:3000/api/hostname
```
# Должен вернуть: ```{"hostname":"<container-id>"}```
