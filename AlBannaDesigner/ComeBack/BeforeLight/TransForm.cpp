#if 0
#include<AdditionalClasses.h>
#include"CBShader.h"
#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Other Libs
#include <SOIL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Other includes
//#include "Shader.h"
//#include"camera.h"

int main()
{
	glm::vec4 vec(1.0f, 2.0f, 3.0f, 1.0f);//Êֽֿםֿ דÊּו ַבדזײÚ בבּ׃ד 
	glm::mat4 trans;//ההװםֶ דױÝזÝֹ ַָׁÚםֹ דָׁÚֹ 
	//ÊÚָׁ ו׀ו ַבדױÝזÝֹ Úה ַבהÞב זבבÚבד ÝַבדױÝזÝַÊ םÊד ַהװֶַוַ ַÝÊַׁײםַ ßדױÝזÝֹ זֹֽֿ 
	//ֳל ּדםÚ Úהַױׁ ַבÞ״ׁ ַבֳׁם׃ם Ê׃ַזם זַֽֿ ױֽםֽ ָםהדַ ָÞםֹ ַבÚהַױׁ Ê׃ַזם ױÝׁ 
	// בו׀ַ םדßה Ê״ָםÞ ַבÚדבםַÊ ַבֽ׃ַָםֹ דה ײָׁ זּדÚ זÛםׁודַ Úבםוַ דַָװֹׁ
	trans = glm::translate(trans,glm::vec3(2.0f,0.3f,0.4f));//דַםÊד Ýם ַבזַÞÚ וז ֵײַÝֹ ַבדÊּו ַבֻבַֻם ַבל ַבױÝ ַבַ־םׁ דה ַבדױÝזÝֹ
	//ז״ָÚַ ÊָÞל ֱַ־ׁ Þםדֹ Ýם ַבדױÝזÝֹ ום זַֽֿ ßדַ ום 
	vec = trans*vec;//״ָÚַ ַב־״זֹ ַבֳ־םֹׁ ום ײָׁ ַבדÊּו Ýם דױÝזÝֹ ַבÊֽזםב זום Ýם ַֽבÊהַ דױÝזÝֹ ַבהÞב
	//הבַֽÙ ַה ו׀ַ ַבײָׁ Ûםׁ Êַָֿבם ַם ַהו בַםּזׂ ײָׁ זײÚ ַבדÊּו ַזבַ vec*trans
	//זבַßה בַָֿ דה ײָׁ ַבדױÝזÝֹ Ýם ַבדÊּו ֽÊל םÊד ַבהÞב בֳהו ֵ׀ַ Êד ײָׁ ַבדÊּו Ýם ַבדױÝזÝֹ ַם ָÚß׃ ַבÊׁÊםָ
	//Ý׃םÊד Êַּוב Þםד ַבהÞב ֽםֻ ׃הֽױב Úבל דױÝזÝֹ  mat(4X1)
	//זום ׃Êדֻב דÊּו ÝÚבַ זבַßהו דÊּו ם׃ַזם ַבדÊּו ַבֳזב ׁÛד ַה ַבֳזב ßַה mat(1X4)
	//זו׀ַ ֳדׁ םָּ ַבַהÊַָו בו ּםַֿ 

	//׃הÞזד ָ״ָםÚֹ ַבַֽב ָÚׁײ ַבדÊּו ַבּֿםֿ זַב׀ם ׃ם׃ַזם דּדזÚ ַבÞםד ַבדהַÙֹׁ בßב דֽזׁ 
	//בַה ַבדױÝזÝֹ דױÝזÝֹ ׀ַÊ ַבÞ״ׁ ַבדזֽֿ
	std::cout << "vec is " << vec.x << " , " << vec.y << " , " << vec.z << std::endl;
	system("pause");
	return 0;
}
#endif