INCLUDE_DIRECTORIES("${PROJECT_INCLUDE_DIR}")

SET(COMMON_SRCS_CLIENTE
	MundoCliente.cpp
	Esfera.cpp
	Plano.cpp	
	Raqueta.cpp	
	Vector2D.cpp)

SET(COMMON_SRCS_SERVIDOR
	MundoServidor.cpp
	Esfera.cpp
	Plano.cpp	
	Raqueta.cpp	
	Vector2D.cpp)
	
ADD_EXECUTABLE(logger logger.cpp)
ADD_EXECUTABLE(bot bot.cpp)
ADD_EXECUTABLE(cliente cliente.cpp ${COMMON_SRCS_CLIENTE}) 
ADD_EXECUTABLE(servidor servidor.cpp ${COMMON_SRCS_SERVIDOR}) 

TARGET_LINK_LIBRARIES(cliente glut GL GLU -lpthread)
TARGET_LINK_LIBRARIES(servidor glut GL GLU -lpthread)
