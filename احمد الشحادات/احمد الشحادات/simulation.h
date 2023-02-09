#ifndef YSGL_sim
#define YSGL_sim
#include <YSGLall.h>

YS3dModel_OBJ myHeli, myTree;
YSCamera myCam;
YSTexture texRoad, texearth, texsky, texwater;
YSTexture texbox, texbox2;
YSTexture texcon, texcon1, texcon2, texcon3;
YSTexture textrain, textrain1, textrain2, textrain3, texrailway;
YSTexture texBuilding, texBuilding1, texBuilding2, textiles, texHelipad, texStation, texwin, texcdoor;


void YSGL_init()
{
	char SuperFolder[] = "D:\\ahmad alshhadat GL\\resources\\";
	

	texwater.load("texture\\water.bmp", SuperFolder);
	texStation.load("texture\\wall.bmp", SuperFolder);
	texHelipad.load("texture\\Helipad.bmp", SuperFolder);
	textiles.load("texture\\tiles.bmp", SuperFolder);
	texBuilding.load("texture\\Building.bmp", SuperFolder);
	texBuilding1.load("texture\\Building1.bmp", SuperFolder);
	texBuilding2.load("texture\\Building2.bmp", SuperFolder);
	texwin.load("texture\\win.bmp", SuperFolder);
	texcdoor.load("texture\\cdoor.bmp", SuperFolder);

	texrailway.load("texture\\road_rails.bmp", SuperFolder);
	textrain.load("texture\\train.bmp", SuperFolder);
	textrain1.load("texture\\train1.bmp", SuperFolder);
	textrain2.load("texture\\in train.bmp", SuperFolder);
	textrain3.load("texture\\in train1.bmp", SuperFolder);

	texcon.load("texture\\container.bmp", SuperFolder);
	texcon1.load("texture\\container1.bmp", SuperFolder);
	texcon2.load("texture\\container2.bmp", SuperFolder);
	texcon3.load("texture\\container3.bmp", SuperFolder);

	texbox2.load("texture\\box.bmp", SuperFolder);
	texbox.load("texture\\WoodBox.bmp", SuperFolder);

	texsky.load("texture\\sky1.bmp", SuperFolder);
	texearth.load("texture\\earth.bmp", SuperFolder);
	texRoad.load("texture\\road.bmp", SuperFolder);

	myTree.load("tree\\tree trunck.obj", "tree\\treet2.bmp", SuperFolder);
	myHeli.load("heli\\Heli.obj", "heli\\leviathnbody8bit256.bmp", SuperFolder);
	
	myHeli.sc = 0.02;

	myCam.Position.z = 15;
	myCam.Position.y = 2;
}

//sky
void sky(){
	//front
	glPushMatrix();
	{
		glRotatef(180, 0, 0, 1);
		glTranslatef(0, -60, -40);
		texsky.draw(60, 1, 1);
	}
	glPopMatrix();

	//front
	glPushMatrix();
	{
		glRotatef(180, 0, 0, 1);
		glTranslatef(0, -60, 40);
		texsky.draw(60, 1, 1);
	}
	glPopMatrix();

	//left
	glPushMatrix();
	{
		glRotatef(90, 0, 1, 0);
		glRotatef(180, 0, 0, 1);
		glTranslatef(0, -60, -40);
		texsky.draw(60, 1, 1);
	}
	glPopMatrix();

	//right
	glPushMatrix();
	{
		glRotatef(-90, 0, 1, 0);
		glRotatef(180, 0, 0, 1);
		glTranslatef(0, -60, -40);
		texsky.draw(60, 1, 1);
	}
	glPopMatrix();

	//top
	glPushMatrix();
	{
		glTranslatef(0, 80, 0);
		glRotatef(90, 1, 0, 0);
		texsky.draw(60, 1, 1);
	}
	glPopMatrix();
}

//earth
void earth()
{
	glPushMatrix();
	{
		glTranslatef(0, 0, 0);
		glRotatef(90, 1, 0, 0);
		texearth.draw(40, 30, 30);
	}
	glPopMatrix();
}

//Road
void Road(float Road_d = 3.5, float Road_t = 0, float Road_x = 0, float Road_y = 0, float Road_z = 0)
{
	glPushMatrix();
	{
		glTranslatef(Road_x, Road_y, Road_z);
		
		glPushMatrix();
		{
			glTranslatef(0, 0.1, -8);
			glRotatef(90, 1, 0, 0);
			if (Road_t==1)
			{
				glRotatef(90, 0, 0, 1);
			}
			glScalef(15, 1, 1);
			texRoad.draw(Road_d, 20, 2);
		}
		glPopMatrix();
	}
	glPopMatrix();
}

//WoodBox
void WoodBox(float box_x = 0, float box_y = 1, float box_z = 0, int tyepbox = 0){
	//WoodBox
	glPushMatrix();
	{
		glTranslatef(box_x, box_y, box_z);
		
		//baek
		glPushMatrix();
		{
			glTranslatef(0, 0, -1);
			if (tyepbox == 0)
				texbox.draw();
			else
				texbox2.draw();
			
		}
		glPopMatrix();

		//front
		glPushMatrix();
		{
			glTranslatef(0, 0, 1);
			if (tyepbox == 0)
				texbox.draw();
			else
				texbox2.draw();

		}
		glPopMatrix();

		//right
		glPushMatrix();
		{
			glRotatef(90, 0, 1, 0);
			glTranslatef(0, 0, 1);
			if (tyepbox == 0)
				texbox.draw();
			else
				texbox2.draw();
		}
		glPopMatrix();

		//left
		glPushMatrix();
		{
			glRotatef(90, 0, 1, 0);
			glTranslatef(0, 0, -1);
			if (tyepbox == 0)
				texbox.draw();
			else
				texbox2.draw();
		}
		glPopMatrix();

		//top
		glPushMatrix();
		{
			glRotatef(90, 1, 0, 0);
			glTranslatef(0, 0, -1);
			if (tyepbox == 0)
				texbox.draw();
			else
				texbox2.draw();
		}
		glPopMatrix();

		//bottom
		glPushMatrix();
		{
			glRotatef(90, 1, 0, 0);
			glTranslatef(0, 0, 1);
			if (tyepbox == 0)
				texbox.draw();
			else
				texbox2.draw();
		}
		glPopMatrix();

	}
	glPopMatrix();
}

//container
void container(float container_x = 0, float container_y = 1, float container_z = 0, int tyepcontainer = 0)
{
	glPushMatrix();
	{
		glTranslatef(container_x, container_y, container_z);
		glRotatef(90, 0, 1, 0);
		

		//bottom
		glPushMatrix();
		{
			glRotatef(90, 1, 0, 0);
			glRotatef(90, 0,0, 1);
			glTranslatef(0, 0, 1);
			glScalef(2, 1, 1);
			if (tyepcontainer==0)
				texcon1.draw(1.5, 1, 1);
			else
				texcon2.draw(1.5, 1, 1);
		}
		glPopMatrix();

		//baek
		glPushMatrix();
		{
			glTranslatef(0, .5, -3);
			if (tyepcontainer == 0)
				texcon.draw(1.5, 1, 1);
			else
				texcon3.draw(1.5, 1, 1);
		}
		glPopMatrix();

		//font
		glPushMatrix();
		{
			glTranslatef(0, 0.5, 3);
			if (tyepcontainer == 0)
				texcon.draw(1.5, 1, 1);
			else
				texcon3.draw(1.5, 1, 1);
		}
		glPopMatrix();

		//right
		glPushMatrix();
		{
			glRotatef(90, 0, 1, 0);
			glTranslatef(0, 0.5, 1.5);
			glScalef(2, 1, 1);
			if (tyepcontainer == 0)
				texcon1.draw(1.5, 1, 1);
			else
				texcon2.draw(1.5, 1, 1);
		}
		glPopMatrix();

		//left
		glPushMatrix();
		{
			glRotatef(90, 0, 1, 0);
			glTranslatef(0, 0.5, -1.5);
			glScalef(2, 1, 1);
			if (tyepcontainer == 0)
				texcon1.draw(1.5, 1, 1);
			else
				texcon2.draw(1.5, 1, 1);
		}
		glPopMatrix();

		//top
		glPushMatrix();
		{
			glRotatef(90, 1, 0, 0);
			glRotatef(90, 0, 0, 1);
			glTranslatef(0, 0, -2);
			glScalef(2, 1, 1);
			if (tyepcontainer == 0)
				texcon1.draw(1.5, 1, 1);
			else
				texcon2.draw(1.5, 1, 1);
		}
		glPopMatrix();

	}
	glPopMatrix();
}

//train
void train(float train_x = 0, float train_y = 1, float train_z = 0)
{
	for (float i = -6.2; i < 18.6; i += 6.2)
	{
	glPushMatrix();
	{
			glTranslatef(train_x + i, train_y, train_z);
			glRotatef(90, 0, 1, 0);
		
			//baek
			glPushMatrix();
			{
				glTranslatef(0, 0, -3);
				textrain3.draw();
			}
			glPopMatrix();

			//baek in train
			glPushMatrix();
			{
				glTranslatef(0, 0, -2.9);
				textrain3.draw();
			}
			glPopMatrix();



			//front
			glPushMatrix();
			{
				glTranslatef(0, 0, 3);
				textrain3.draw();
			}
			glPopMatrix();

			//front in train
			glPushMatrix();
			{
				glTranslatef(0, 0, 2.9);
				textrain3.draw();
			}
			glPopMatrix();

			//right
			glPushMatrix();
			{
				glRotatef(90, 0, 1, 0);
				glTranslatef(0, 0, 1);
				glScalef(3, 1, 1);
				textrain.draw();
			}
			glPopMatrix();

			//in train right
			glPushMatrix();
			{
				glRotatef(90, 0, 1, 0);
				glTranslatef(0, 0, 0.99);
				glScalef(3, 1, 1);
				textrain2.draw();
			}
			glPopMatrix();

			//left
			glPushMatrix();
			{
				glRotatef(90, 0, 1, 0);
				glTranslatef(0, 0, -1);
				glScalef(3, 1, 1);
				textrain.draw();
			}
			glPopMatrix();

			//train right left
			glPushMatrix();
			{
				glRotatef(90, 0, 1, 0);
				glTranslatef(0, 0, -0.99);
				glScalef(3, 1, 1);
				textrain2.draw();
			}
			glPopMatrix();

			//top
			glPushMatrix();
			{
				glRotatef(90, 1, 0, 0);
				glRotatef(90, 0, 0, 1);
				glTranslatef(0, 0, -1);
				glScalef(3, 1, 1);
				textrain1.draw();
			}
			glPopMatrix();

			//bottom
			glPushMatrix();
			{
				glRotatef(90, 1, 0, 0);
				glRotatef(90, 0, 0, 1);
				glTranslatef(0, 0, 1);
				glScalef(3, 1, 1);
				textrain1.draw();
			}
			glPopMatrix();


		}
		glPopMatrix();
	}
}

//Building
void Buil(float Building_x = 0, float Building_y = 0, float Building_z = 0, float tyepbuil=0){
	glPushMatrix();
	{
		glTranslatef(Building_x, Building_y, Building_z);

		//bottom
		glPushMatrix();
		{
			glRotatef(90, 1, 0, 0);
			glTranslatef(0, -5, 0);
			textiles.draw(8, 10, 10);
		}
		glPopMatrix();

		//front
		glPushMatrix();
		{
			glTranslatef(0, 15, 0);
			glScalef(5, 15, 1);
			if (tyepbuil == 0)
				texBuilding.draw();
			if (tyepbuil == 1)
				texBuilding1.draw();
			if (tyepbuil == 2)
				texBuilding2.draw();

		}
		glPopMatrix();

		//back
		glPushMatrix();
		{
			glTranslatef(0, 15, -10);
			glScalef(5, 15, 1);
			if (tyepbuil == 0)
				texBuilding.draw();
			if (tyepbuil == 1)
				texBuilding1.draw();
			if (tyepbuil == 2)
				texBuilding2.draw();
		}
		glPopMatrix();

		//right
		glPushMatrix();
		{
			glRotatef(90, 0, 1, 0);
			glTranslatef(5, 15, 5);
			glScalef(5, 15, 1);
			if (tyepbuil == 0)
				texBuilding.draw();
			if (tyepbuil == 1)
				texBuilding1.draw();
			if (tyepbuil == 2)
				texBuilding2.draw();
		}
		glPopMatrix();

		//left
		glPushMatrix();
		{
			glRotatef(90, 0, 1, 0);
			glTranslatef(5, 15, -5);
			glScalef(5, 15, 1);
			if (tyepbuil == 0)
				texBuilding.draw();
			if (tyepbuil == 1)
				texBuilding1.draw();
			if (tyepbuil == 2)
				texBuilding2.draw();
		}
		glPopMatrix();

		//top/
		glPushMatrix();
		{
			glRotatef(90, 1, 0, 0);
			glTranslatef(0, -5, -30);
			glScalef(5, 5, 1);
			texHelipad.draw();
		}
		glPopMatrix();

		//myHeli
		glPushMatrix();
		{
			
			glTranslatef(-0.4, 31.2, -5);
			glRotatef(180, 0, 1, 0);
			glScalef(5, 5, 5);
			myHeli.draw();
		}
		glPopMatrix();
	}
	glPopMatrix();
}

//win
void win(float win_x, float win_y, float win_z){
	
	glPushMatrix();
	{
		glTranslatef(win_x, win_y, win_z);
		texwin.draw();
	}
	glPopMatrix();
}

//Station building
void Station(float Station_x = 0, float Station_y = 0, float Station_z = -30){
	glPushMatrix();
	{

		glTranslatef(Station_x, Station_y, Station_z);

		//train Station
		glPushMatrix();
		{
			glTranslatef(0, 5, 2.5);
			glScalef(2, 2, 2);
			glColor3f(0, 0, 0);
			ysPrintf("train Station");
		}
		glPopMatrix();

		//wins
		win(8, 3, 2.5);
		win(5, 3, 2.5);
		win(-8, 3, 2.5);
		win(-5, 3, 2.5);

		//cdoor
		glPushMatrix();
		{
			glTranslatef(0, 2, 2.5);
			glScalef(2.5, 2, 1);
			texcdoor.draw();
		}
		glPopMatrix();
		
		//bottim
		glPushMatrix();
		{
			glRotatef(90, 1, 0, 0);
			glScalef(10, 2.5, .5);
			textiles.draw();
		}
		glPopMatrix();

		//back
		glPushMatrix();
		{
			glTranslatef(0, 2.5, -2.5);
			glScalef(10, 2.5, .5);
			texStation.draw();
		}
		glPopMatrix();

		//front
		glPushMatrix();
		{
			glTranslatef(0, 2.5, 2.5);
			glScalef(10, 2.5, .5);
			texStation.draw();
		}
		glPopMatrix();

		//right
		glPushMatrix();
		{
			glTranslatef(10, 2.5, 0);
			glRotatef(90, 0, 1, 0);
			glScalef(2.5, 2.5, .5);
			texStation.draw();
		}
		glPopMatrix();

		//LEFT
		glPushMatrix();
		{
			glTranslatef(-10, 2.5, 0);
			glRotatef(90, 0, 1, 0);
			glScalef(2.5, 2.5, .5);
			texStation.draw();
		}
		glPopMatrix();

		//top
		glPushMatrix();
		{
			glTranslatef(0, 5, 0);
			glRotatef(90, 1, 0, 0);
			glScalef(10, 2.5, .5);
			texStation.draw();
		}
		glPopMatrix();


	}
	glPopMatrix();
}

//myTree
void Tree(float Tree_x = 0, float Tree_y = 0, float Tree_z = 0)
{
	static float theta = 0;
	theta += 1;
	glPushMatrix();
	{

		glTranslatef(Tree_x, Tree_y, Tree_z);
		glRotatef(0.1 * ysSinD(theta), 0, 0, 1);
		myTree.draw();
	}
	glPopMatrix();
}

//railway
void railway(float railway_x = 0, float railway_y = 0, float railway_z = 0)
{
	glPushMatrix();
	{
		glTranslatef(railway_x, railway_y, railway_z);
		glRotatef(90, 0, 0, 1);
		glRotatef(90, 0, 1, 0);
		glPushMatrix();
		{
			glScalef(1, 15, 1);
			texrailway.draw(3.5, 2, 20);
			
		}
		glPopMatrix();
	}
	glPopMatrix();
}

//fountain
void fountain(float fountain_x = 0, float fountain_y = 0, float fountain_z = 0){

	glPushMatrix();
	{
		glTranslatef(fountain_x, fountain_y, fountain_z);
		
		//bottom
		glPushMatrix();
		{
			glTranslatef(0, 0, 6);
			glRotatef(-90, 1, 0, 0);
			texwater.draw(4, 4, 2);
		}
		glPopMatrix();

		//bottom
		glPushMatrix();
		{
			glTranslatef(0, .7, 6);
			glRotatef(-90, 1, 0, 0);
			texwater.draw(4, 4, 2);
		}
		glPopMatrix();

		//back1
		glPushMatrix();
		{
			glTranslatef(0, .5, 2);
			glScalef(4, .5, 1);
			texStation.draw(1, 5, 1);
		}
		glPopMatrix();

		//front

		glPushMatrix();
		{
			glTranslatef(0, 0.5, 10);
			glScalef(4, .5, 1);
			texStation.draw(1, 5, 1);
		}
		glPopMatrix();
		
		//right
		glPushMatrix();
		{

			glTranslatef(-4, 0.5, 6);
			glRotatef(90, 0, 1, 0);
			glScalef(4, .5, 1);
			
			texStation.draw(1,5,1);
		}
		glPopMatrix();

		//Left
		glPushMatrix();
		{

			glTranslatef(4, 0.5, 6);
			glRotatef(90, 0, 1, 0);
			glScalef(4, .5, 1);

			texStation.draw(1, 5, 1);
		}
		glPopMatrix();


		}
		glPopMatrix();
}


void YSGL_mainGL()
{

	//sky
	sky();

	//Road
	Road();
	Road(2,1,17.5,0,30);
	Road(2, 1, -17.5, 0, 30);
	Road(2, 0,30, 0, 25);
	Road(2, 0, -30, 0, 25);


	//railway
	railway(0, 0, -32);
	railway(0, 0, -22);


	//container
	for (int i = -36; i <= 37; i+=8)
	{
		container(i, 1, -38);
		if (i<35)
			container(4 + i, 4, -38,1);
	}

	//WoodBox
	for (float i = -25; i < 30; i+=6)
	{
		WoodBox(i, 1, -27); 
		WoodBox(i+3, 1, -27, 1);
		WoodBox(i + 1.5, 3, -27);
		if (i<29)
			WoodBox(i + 4.5, 3, -27, 1);	
	}


	//train
	train(20, 1.1, -30.1);
	train(-15, 1.1, -33.6);
	train(-20, 1.1, -20.1);
	train(15, 1.1, -23.6);


	//Station
	Station(0,0,-15);
	

	//Tree
	for (int i = 12; i < 38; i += 2)
	{
		Tree(i, 0, -13);
		Tree(i, 0, -16);
	}
		
	for (int i = -12; i > -38; i -= 2)
	{
		Tree(i, 0, -13);
		Tree(i, 0, -16);
	}

	for (int i = 0; i < 28; i += 2)
	{
		Tree(-13 + i, 0, 0);
		Tree(-13 + i, 0, -2);
	}

	for (int i = 0; i < 28; i += 2)
	{
		Tree(-13 + i, 0, 12);
		Tree(-13 + i, 0, 14);
	}

	//fountain
	fountain();

	//Building
	Buil(30,0,10);
	Buil(30, 0, 35);
	
	Buil(-5, 0, 35, 1);
	Buil(5, 0, 35, 1);

	Buil(-30, 0, 10, 2);
	Buil(-30, 0, 35, 2);

	//earth
	earth();
	

	Sleep(10);
}

#endif