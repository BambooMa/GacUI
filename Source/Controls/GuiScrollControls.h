/***********************************************************************
Vczh Library++ 3.0
Developer: Zihan Chen(vczh)
GacUI::Control System

Interfaces:
***********************************************************************/

#ifndef VCZH_PRESENTATION_CONTROLS_GUISCROLLCONTROLS
#define VCZH_PRESENTATION_CONTROLS_GUISCROLLCONTROLS

#include "GuiBasicControls.h"

namespace vl
{
	namespace presentation
	{

		namespace controls
		{

/***********************************************************************
Scrolls
***********************************************************************/

			/// <summary>A scroll control, which represents a one dimension sub range of a whole range.</summary>
			class GuiScroll : public GuiControl, public Description<GuiScroll>
			{
			public:
				/// <summary>A command executor for the style controller to change the control state.</summary>
				class ICommandExecutor : public virtual IDescriptable, public Description<ICommandExecutor>
				{
				public:
					/// <summary>Do small decrement.</summary>
					virtual void						SmallDecrease()=0;
					/// <summary>Do small increment.</summary>
					virtual void						SmallIncrease()=0;
					/// <summary>Do big decrement.</summary>
					virtual void						BigDecrease()=0;
					/// <summary>Do big increment.</summary>
					virtual void						BigIncrease()=0;

					/// <summary>Change to total size of the scroll.</summary>
					/// <param name="value">The total size.</param>
					virtual void						SetTotalSize(vint value)=0;
					/// <summary>Change to page size of the scroll.</summary>
					/// <param name="value">The page size.</param>
					virtual void						SetPageSize(vint value)=0;
					/// <summary>Change to position of the scroll.</summary>
					/// <param name="value">The position.</param>
					virtual void						SetPosition(vint value)=0;
				};
				
				/// <summary>Style controller interface for <see cref="GuiScroll"/>.</summary>
				class IStyleController : public virtual GuiControl::IStyleController, public Description<IStyleController>
				{
				public:
					/// <summary>Called when the command executor is changed.</summary>
					/// <param name="value">The command executor.</param>
					virtual void						SetCommandExecutor(ICommandExecutor* value)=0;
					/// <summary>Called when the total size is changed.</summary>
					/// <param name="value">The total size.</param>
					virtual void						SetTotalSize(vint value)=0;
					/// <summary>Called when the page size is changed.</summary>
					/// <param name="value">The page size.</param>
					virtual void						SetPageSize(vint value)=0;
					/// <summary>Called when the position is changed.</summary>
					/// <param name="value">The position.</param>
					virtual void						SetPosition(vint value)=0;
				};
			protected:
				class CommandExecutor : public Object, public ICommandExecutor
				{
				protected:
					GuiScroll*							scroll;
				public:
					CommandExecutor(GuiScroll* _scroll);
					~CommandExecutor();

					void								SmallDecrease()override;
					void								SmallIncrease()override;
					void								BigDecrease()override;
					void								BigIncrease()override;

					void								SetTotalSize(vint value)override;
					void								SetPageSize(vint value)override;
					void								SetPosition(vint value)override;
				};

				IStyleController*						styleController;
				Ptr<CommandExecutor>					commandExecutor;
				vint									totalSize;
				vint									pageSize;
				vint									position;
				vint									smallMove;
				vint									bigMove;
			public:
				/// <summary>Create a control with a specified style controller.</summary>
				/// <param name="_styleController">The style controller.</param>
				GuiScroll(IStyleController* _styleController);
				~GuiScroll();
				
				/// <summary>Total size changed event.</summary>
				compositions::GuiNotifyEvent			TotalSizeChanged;
				/// <summary>Page size changed event.</summary>
				compositions::GuiNotifyEvent			PageSizeChanged;
				/// <summary>Position changed event.</summary>
				compositions::GuiNotifyEvent			PositionChanged;
				/// <summary>Small move changed event.</summary>
				compositions::GuiNotifyEvent			SmallMoveChanged;
				/// <summary>Big move changed event.</summary>
				compositions::GuiNotifyEvent			BigMoveChanged;
				
				/// <summary>Get the total size.</summary>
				/// <returns>The total size.</returns>
				virtual vint							GetTotalSize();
				/// <summary>Set the total size.</summary>
				/// <param name="value">The total size.</param>
				virtual void							SetTotalSize(vint value);
				/// <summary>Get the page size.</summary>
				/// <returns>The page size.</returns>
				virtual vint							GetPageSize();
				/// <summary>Set the page size.</summary>
				/// <param name="value">The page size.</param>
				virtual void							SetPageSize(vint value);
				/// <summary>Get the position.</summary>
				/// <returns>The position.</returns>
				virtual vint							GetPosition();
				/// <summary>Set the position.</summary>
				/// <param name="value">The position.</param>
				virtual void							SetPosition(vint value);
				/// <summary>Get the small move.</summary>
				/// <returns>The small move.</returns>
				virtual vint							GetSmallMove();
				/// <summary>Set the small move.</summary>
				/// <param name="value">The small move.</param>
				virtual void							SetSmallMove(vint value);
				/// <summary>Get the big move.</summary>
				/// <returns>The big move.</returns>
				virtual vint							GetBigMove();
				/// <summary>Set the big move.</summary>
				/// <param name="value">The big move.</param>
				virtual void							SetBigMove(vint value);
				
				/// <summary>Get the minimum possible position.</summary>
				/// <returns>The minimum possible position.</returns>
				vint									GetMinPosition();
				/// <summary>Get the maximum possible position.</summary>
				/// <returns>The maximum possible position.</returns>
				vint									GetMaxPosition();
			};
		}
	}
}

#endif
