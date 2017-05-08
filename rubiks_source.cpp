#include <vtkCubeSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkProperty.h>
#include <vtkSmartPointer.h>
#include <vtkMinimalStandardRandomSequence.h>

#include "rubiks_source.h"

int main()
{
	vtkSmartPointer<vtkActor> tableau[12][9];
	// Cone source
	//vtkConeSource *coneSource = vtkConeSource::New();
	vtkSmartPointer<vtkCubeSource> cubeSource = 
		vtkSmartPointer<vtkCubeSource>::New();
	cubeSource->SetXLength(1.9);
	cubeSource->SetYLength(1.9);
	cubeSource->SetZLength(1.9);
	cubeSource->Update();

	// PolyDataMapper
	//vtkPolyDataMapper *polyDataMapper = vtkPolyDataMapper::New();
	vtkSmartPointer<vtkPolyDataMapper> polyDataMapper = 
		vtkSmartPointer<vtkPolyDataMapper>::New();
	polyDataMapper->SetInputConnection(cubeSource->GetOutputPort());



	// Actor
	//vtkActor *actor = vtkActor::New();
	//vtkSmartPointer<vtkActor> actor = 
	//	vtkSmartPointer<vtkActor>::New();
	//actor->SetMapper(polyDataMapper);

	// Property to change cone color
	//vtkSmartPointer<vtkProperty> colorProperty = 
	//	vtkSmartPointer<vtkProperty>::New();
	//colorProperty->SetColor(1,0,0);
	//actor->SetProperty(colorProperty);

	// Renderer
	//vtkRenderer *renderer = vtkRenderer::New();
	vtkSmartPointer<vtkRenderer> renderer = 
		vtkSmartPointer<vtkRenderer>::New();
	renderer->SetBackground(0.1, 0.2, 0.4);
	//renderer->AddActor(actor);

	// Random sequence
	vtkSmartPointer<vtkMinimalStandardRandomSequence> sequence = 
      vtkSmartPointer<vtkMinimalStandardRandomSequence>::New();
	sequence->SetSeed(1);

	double yspacing = 2.0, zspacing = 2.0, wspacing = 2.0;
	
	for (int h=0; h <3; h++)
	{
		double w = wspacing * h;
		for (int j=0; j<3; j++)
		{
			double y = yspacing * j;
			for (int k=0; k<3; k++)
			{
				double z = zspacing * k;

				vtkSmartPointer<vtkActor> actor = 
					vtkSmartPointer<vtkActor>::New();
				actor->SetMapper(polyDataMapper);
				actor->SetPosition(w, y, z);
			
				vtkSmartPointer<vtkProperty> colorProperty = 
					vtkSmartPointer<vtkProperty>::New();
				/*sequence->Next();
				double r = sequence->GetValue();
				sequence->Next();
				double g = sequence->GetValue();
				sequence->Next();
				double b = sequence->GetValue();
				colorProperty->SetColor(r,g,b);*/
				colorProperty->SetColor(0.05,0.05,0.05);
			
				actor->SetProperty(colorProperty);
			
				renderer->AddActor(actor);
			}
		}
	}
	

	
	vtkSmartPointer<vtkCubeSource> faceSource = 
		vtkSmartPointer<vtkCubeSource>::New();
	faceSource->SetXLength(1.7);
	faceSource->SetYLength(1.7);
	faceSource->SetZLength(0.05);
	faceSource->Update();
	
	vtkSmartPointer<vtkPolyDataMapper> polyDataMapper2 = 
		vtkSmartPointer<vtkPolyDataMapper>::New();
	polyDataMapper2->SetInputConnection(faceSource->GetOutputPort());

	for (int h=0; h <3; h++)
	{
		double w = wspacing * h;
		for (int j=0; j<3; j++)
		{
			double y = yspacing * j;
			for (int k=0; k<4; k++)
			{
				if(k !=1 && k!=2)
				{
					double z = zspacing * k - 1.0;

					vtkSmartPointer<vtkActor> actor2 = 
						vtkSmartPointer<vtkActor>::New();
					actor2->SetMapper(polyDataMapper2);
					actor2->SetPosition(w, y, z);
			
					vtkSmartPointer<vtkProperty> colorProperty = 
						vtkSmartPointer<vtkProperty>::New();
					if(k==0) {
						colorProperty->SetColor(1,0.5,0); //Face orange			
						actor2->SetProperty(colorProperty);
						tableau[9+h][3+j] = actor2;
					}
					else {
						colorProperty->SetColor(1,0,0); //Face rouge			
						actor2->SetProperty(colorProperty);
						tableau[3+h][3+j] = actor2;
					}
			
					renderer->AddActor(actor2);
				}
			}
		}
	}

	vtkSmartPointer<vtkCubeSource> faceSource2 = 
		vtkSmartPointer<vtkCubeSource>::New();
	faceSource2->SetXLength(0.05);
	faceSource2->SetYLength(1.7);
	faceSource2->SetZLength(1.7);
	faceSource2->Update();
	
	vtkSmartPointer<vtkPolyDataMapper> polyDataMapper3 = 
		vtkSmartPointer<vtkPolyDataMapper>::New();
	polyDataMapper3->SetInputConnection(faceSource2->GetOutputPort());

	
	for (int k=0; k<3; k++)
	{
		double z = zspacing * k;
		for (int j=0; j<3; j++)
		{
			double y = yspacing * j;
			for (int h=0; h <4; h++)
			{
				if(h !=1 && h!=2)
				{
					double w = wspacing * h  - 1.0;

					vtkSmartPointer<vtkActor> actor3 = 
						vtkSmartPointer<vtkActor>::New();
					actor3->SetMapper(polyDataMapper3);
					actor3->SetPosition(w, y, z);
			
					vtkSmartPointer<vtkProperty> colorProperty = 
						vtkSmartPointer<vtkProperty>::New();
					if(h==0) {
						colorProperty->SetColor(0,0.5,0); //Face verte
						actor3->SetProperty(colorProperty);
						tableau[k][3+j] = actor3;
					}
					else {
						colorProperty->SetColor(0,0,1); //Face bleu
						actor3->SetProperty(colorProperty);
						tableau[6+k][3+j] = actor3;
					}
			
					renderer->AddActor(actor3);
				}
			}
		}
	}

	vtkSmartPointer<vtkCubeSource> faceSource3 = 
		vtkSmartPointer<vtkCubeSource>::New();
	faceSource3->SetXLength(1.7);
	faceSource3->SetYLength(0.05);
	faceSource3->SetZLength(1.7);
	faceSource3->Update();
	
	vtkSmartPointer<vtkPolyDataMapper> polyDataMapper4 = 
		vtkSmartPointer<vtkPolyDataMapper>::New();
	polyDataMapper4->SetInputConnection(faceSource3->GetOutputPort());

	
	for (int k=0; k<3; k++)
	{
		double z = zspacing * k;
		for (int h=0; h<3; h++)
		{
			double w = wspacing * h;
			for (int j=0; j <4; j++)
			{
				if(j !=1 && j!=2)
				{
					double y = yspacing * j  - 1.0;

					vtkSmartPointer<vtkActor> actor4 = 
						vtkSmartPointer<vtkActor>::New();
					actor4->SetMapper(polyDataMapper4);
					actor4->SetPosition(w, y, z);
			
					vtkSmartPointer<vtkProperty> colorProperty = 
						vtkSmartPointer<vtkProperty>::New();
					if(j==0) {
						colorProperty->SetColor(1,1,0); //Face jaune
						actor4->SetProperty(colorProperty);
						tableau[3+k][6+h] = actor4;
					}
					else {
						colorProperty->SetColor(1,1,1); //Face blanche
						actor4->SetProperty(colorProperty);
						tableau[3+k][h] = actor4;
					}
			
					renderer->AddActor(actor4);
				}
			}
		}
	}


	// Render window
	//vtkRenderWindow *renderWindow = vtkRenderWindow::New();
	vtkSmartPointer<vtkRenderWindow> renderWindow = 
		vtkSmartPointer<vtkRenderWindow>::New();
	renderWindow->AddRenderer(renderer);

	// Render window interactor
	//vtkRenderWindowInteractor *renderWindowInteractor = vtkRenderWindowInteractor::New();
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = 
		vtkSmartPointer<vtkRenderWindowInteractor>::New();
	renderWindowInteractor->SetRenderWindow(renderWindow);

	// Create a new observer 
	vtkSmartPointer<Observer> observer =
		vtkSmartPointer<Observer>::New();
	observer->SetRenderWindowInteractor(renderWindowInteractor);
	observer->SetCubeSource(cubeSource);
	observer->SetTableau(tableau);
	renderWindowInteractor->AddObserver(
		vtkCommand::KeyPressEvent,observer);

	renderWindow->Render();
	renderWindowInteractor->Start();

	// Désallocations
	//coneSource->Delete();
	//polyDataMapper->Delete();
	//actor->Delete();
	//renderer->Delete();
	//renderWindow->Delete();
	//renderWindowInteractor->Delete();

	return 0;
}