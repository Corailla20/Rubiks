#include <vtkCommand.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkCubeSource.h>

class Observer : public vtkCommand {
public:
	static Observer* New() { return new Observer; }
	void Execute(vtkObject*, unsigned long, void*)
	{ 
		static bool up = true;
		
		vtkSmartPointer<vtkProperty> colorProperty = vtkSmartPointer<vtkProperty>::New();
		colorProperty->SetColor(1,0,0); 

		// Vérifier si ‘u’ appuyé
		if (renderWindowInteractor->GetKeyCode() == 'u')
		{
			//Up
			for(int i = 0; i < 12 ; i++)
			{				
				try {
					colorProperty->SetColor(tableau[(i+3)%12][3]->GetProperty()->GetColor());
						
					tableau[i][3]->SetProperty(colorProperty);
				}
				catch(const std::exception & e)
				{
					std::cerr << e.what(); 
				}
			}
		}
		// Vérifier si ‘l’ appuyé
		if (renderWindowInteractor->GetKeyCode() == 'l')
		{
			//Left 
		}
		// Vérifier si ‘r’ appuyé
		if (renderWindowInteractor->GetKeyCode() == 'r')
		{
			//Right
		}
		// Vérifier si ‘d’ appuyé
		if (renderWindowInteractor->GetKeyCode() == 'd')
		{
			//Down
			for(int i = 0; i < 12 ; i++)
			{				
				try {
					colorProperty->SetColor(tableau[(i+3)%12][6]->GetProperty()->GetColor());
						
					tableau[i][6]->SetProperty(colorProperty);
				}
				catch(const std::exception & e)
				{
					std::cerr << e.what(); 
				}
			}
		}		
		// Vérifier si ‘f’ appuyé
		if (renderWindowInteractor->GetKeyCode() == 'f')
		{
			//Face
		}
		
		this->renderWindowInteractor->Render();
	}

	void SetRenderWindowInteractor(vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor)
	{ 
		this->renderWindowInteractor = renderWindowInteractor;
	}

	void SetCubeSource(vtkSmartPointer<vtkCubeSource> cubeSource)
	{ 
		this->cubeSource = cubeSource;
	}

	void SetTableau(vtkSmartPointer<vtkActor> tableau[12][9])
	{ 
		for(int i = 0; i < 12; i++)
		{
			for(int j = 0; j < 9; j++)
			{
				this->tableau[i][j] = tableau[i][j];
			}
		}
	}

protected:

private:
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor;
	vtkSmartPointer<vtkCubeSource> cubeSource;
	vtkSmartPointer<vtkActor> tableau[12][9];
	int MinimumResolution, MaximumResolution;
};