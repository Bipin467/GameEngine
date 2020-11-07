#include "Games/TextureMovement.h"
void MoveTexture::Update()
{
	if (Input::GetInstance().GetMouseButtonDown(MouseButton::LEFT)) {
		int pixDis = 200;
		if (!m_Clicked) {
			m_MousePosition = Input::GetInstance().GetMousePosition();
			m_MouseScreenCoordPos = MouseToScreenPos(m_MousePosition);
			m_Clicked = DetectCollisionUI::DetectCollisionOnCircle(transform, m_MousePosition);;
			m_Selected = m_Clicked;
			Vector2 pos = transform->Position;
			m_Offset = MouseToScreenPos(Input::GetInstance().GetMousePosition()) - pos;
			return;
		}
		m_MousePosition = Input::GetInstance().GetMousePosition();
		m_MouseScreenCoordPos = MouseToScreenPos(m_MousePosition);
		transform->Position = (m_MouseScreenCoordPos - m_Offset);
	}
	else if (Input::GetInstance().GetMouseButtonUp(MouseButton::LEFT)) {
		m_Clicked = false;
	}
	if (Input::GetInstance().GetKeyDown(KeyCode::SPACE)) {
		GetRigidBody()->IsKinematic = !GetRigidBody()->IsKinematic;
	}
	if (m_Selected) {
		transform->Scale += 30*Input::GetInstance().GetScrollOffset().y*Time::GetInstance().DeltaTime();
		if (Input::GetInstance().GetKey(KeyCode::ARROW_UP)|| Input::GetInstance().GetKeyDown(KeyCode::ARROW_UP)) {
			transform->Position.y += Time::DeltaTime();
		}
		else if (Input::GetInstance().GetKey(KeyCode::ARROW_DOWN)|| Input::GetInstance().GetKeyDown(KeyCode::ARROW_DOWN)) {
			transform->Position.y -= Time::DeltaTime();
		}
		if (Input::GetInstance().GetKey(KeyCode::ARROW_LEFT) || Input::GetInstance().GetKeyDown(KeyCode::ARROW_LEFT)) {
			transform->Position.x -= Time::DeltaTime();
		}
		else if (Input::GetInstance().GetKey(KeyCode::ARROW_RIGHT) || Input::GetInstance().GetKeyDown(KeyCode::ARROW_RIGHT)) {
			transform->Position.x += Time::DeltaTime();
		}
		if (Input::GetInstance().GetKey(KeyCode::X) || Input::GetInstance().GetKeyDown(KeyCode::X)) {
			transform->Rotation.z += Time::DeltaTime()*10.0f;
		}
	}
}

Vector2 MoveTexture::MouseToScreenPos(const Vector2& mousePosition)
{
	return Vector2(((mousePosition.x / Screen::Width)-0.5f)*2, (((Screen::Height - mousePosition.y) / Screen::Height)-0.5f)*2);
}

bool MoveTexture::CheckCollision()
{
	float x = transform->Position.x;
	float y = transform->Position.y;
	Vector2 scale = transform->Scale;
	Vector2 min;
	Vector2 max;
	if (scale.x < 0) {
		scale.x *= -1;
	}
	if (scale.y < 0) {
		scale.y *= -1;
	}
	min.x = x - 0.5f*scale.x;
	min.y = y - 0.5f*scale.y;
	max.x = x + 0.5f*scale.x;
	max.y = y + 0.5f*scale.y;
	float tempx = max.x - m_MouseScreenCoordPos.x;
	float tempy = max.y - m_MouseScreenCoordPos.y;
	x = m_MouseScreenCoordPos.x - min.x;
	y = m_MouseScreenCoordPos.y - min.y;
	return !(x * tempx < 0 || y * tempy < 0);
}

