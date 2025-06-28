# Warrior Action RPG (GAS 기반 고급 액션 전투 시스템)

본 프로젝트는 Unreal Engine 5의 Gameplay Ability System(GAS)을 활용해 몰입감 있는 3인칭 액션 RPG 전투를 구현한 프로젝트입니다.

## 🔧 주요 기능
- **전투 시스템**: 가벼운/강한 공격 콤보, 방향성 구르기, 히트 리액션, 방어 및 패링, 특수 능력
- **AI 시스템**: 회피, 스트레이핑, 투사체 공격, 웨이브 생성, 보스전
- **GAS 활용**: 능력 발동, 쿨다운, 비용, UI 연동, 데이터 중심 설계
- **게임 모드**: 생존 모드, 웨이브별 적 생성, 보스 등장의 게임 흐름
- **UI 및 UX**: 타겟 잠금, 알림 시스템, 메인/일시정지/승리/패배 화면
- **기술적 특징**:
  - Custom BTTask, Decorator, Service를 사용한 AI 행동 트리
  - Motion Warping 기반 구르기
  - C++와 블루프린트의 하이브리드 구조
  - 비동기/동기 데이터 로딩, 확장성 높은 전투 통계 구조

## 🛠 기술 스택
- Unreal Engine 5.5
- C++, Blueprint
- Gameplay Ability System (GAS)
- Behavior Tree + EQS
- Niagara VFX, Motion Warping
- Widget UI System

## 📸 플레이 영상

### 타이틀 UI
https://github.com/user-attachments/assets/13ac98b1-d0ea-4765-ba0a-bc5f5584e3f4

### 전투
https://github.com/user-attachments/assets/2fbc7364-9eb7-4928-ab1e-f96333f72831

### 보스전
https://github.com/user-attachments/assets/e2065056-93ed-4b6c-ba6a-1197283e8ec1

https://github.com/user-attachments/assets/7dcfd86a-9e5d-4fea-9d08-47d484d8ea87

## ▶️ 전체 시연
👉 [[유튜브 링크](https://youtu.be/m7ABLmjqDe0)]

---
