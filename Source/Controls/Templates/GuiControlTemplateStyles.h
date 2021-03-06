/***********************************************************************
Vczh Library++ 3.0
Developer: Zihan Chen(vczh)
GacUI::Template System

Interfaces:
***********************************************************************/

#ifndef VCZH_PRESENTATION_CONTROLS_TEMPLATES_GUICONTROLTEMPLATESTYLES
#define VCZH_PRESENTATION_CONTROLS_TEMPLATES_GUICONTROLTEMPLATESTYLES

#include "GuiControlTemplates.h"

namespace vl
{
	namespace presentation
	{
		namespace templates
		{
#pragma warning(push)
#pragma warning(disable:4250)

/***********************************************************************
Control Template
***********************************************************************/

			class GuiControlTemplate_StyleProvider
				: public Object
				, public virtual controls::GuiControl::IStyleController
				, public virtual controls::GuiControl::IStyleProvider
				, public Description<GuiControlTemplate_StyleProvider>
			{
			protected:
				controls::GuiControl::IStyleController*							associatedStyleController;
				GuiControlTemplate*												controlTemplate;

			public:
				GuiControlTemplate_StyleProvider(TemplateProperty<GuiControlTemplate> factory, description::Value viewModel = description::Value());
				~GuiControlTemplate_StyleProvider();

				compositions::GuiBoundsComposition*								GetBoundsComposition()override;
				compositions::GuiGraphicsComposition*							GetContainerComposition()override;
				void															AssociateStyleController(controls::GuiControl::IStyleController* controller)override;
				void															SetFocusableComposition(compositions::GuiGraphicsComposition* value)override;
				void															SetText(const WString& value)override;
				void															SetFont(const FontProperties& value)override;
				void															SetVisuallyEnabled(bool value)override;
			};

			class GuiLabelTemplate_StyleProvider
				: public GuiControlTemplate_StyleProvider
				, public controls::GuiLabel::IStyleController
				, public Description<GuiLabelTemplate_StyleProvider>
			{
			protected:
				GuiLabelTemplate*												controlTemplate;

			public:
				GuiLabelTemplate_StyleProvider(TemplateProperty<GuiLabelTemplate> factory);
				~GuiLabelTemplate_StyleProvider();

				Color															GetDefaultTextColor()override;
				void															SetTextColor(Color value)override;
			};

			class GuiSinglelineTextBoxTemplate_StyleProvider
				: public GuiControlTemplate_StyleProvider
				, public virtual controls::GuiSinglelineTextBox::IStyleProvider
				, public Description<GuiSinglelineTextBoxTemplate_StyleProvider>
			{
			protected:
				GuiSinglelineTextBoxTemplate*									controlTemplate;
				
			public:
				GuiSinglelineTextBoxTemplate_StyleProvider(TemplateProperty<GuiSinglelineTextBoxTemplate> factory);
				~GuiSinglelineTextBoxTemplate_StyleProvider();
				
				void															SetFocusableComposition(compositions::GuiGraphicsComposition* value)override;
				compositions::GuiGraphicsComposition*							InstallBackground(compositions::GuiBoundsComposition* boundsComposition)override;
			};

			class GuiDocumentLabelTemplate_StyleProvider
				: public GuiControlTemplate_StyleProvider
				, public virtual controls::GuiDocumentLabel::IStyleController
				, public Description<GuiDocumentLabelTemplate_StyleProvider>
			{
			protected:
				GuiDocumentLabelTemplate*										controlTemplate;
				
			public:
				GuiDocumentLabelTemplate_StyleProvider(TemplateProperty<GuiDocumentLabelTemplate> factory);
				~GuiDocumentLabelTemplate_StyleProvider();
				
				Ptr<DocumentModel>												GetBaselineDocument()override;
			};

			class GuiMenuTemplate_StyleProvider
				: public GuiControlTemplate_StyleProvider
				, public controls::GuiWindow::DefaultBehaviorStyleController
				, public Description<GuiMenuTemplate_StyleProvider>
			{
			public:
				GuiMenuTemplate_StyleProvider(TemplateProperty<GuiMenuTemplate> factory);
				~GuiMenuTemplate_StyleProvider();
			};

			class GuiWindowTemplate_StyleProvider
				: public GuiControlTemplate_StyleProvider
				, public controls::GuiWindow::IStyleController
				, public Description<GuiWindowTemplate_StyleProvider>
			{
			protected:
				GuiWindowTemplate*												controlTemplate;
				controls::GuiWindow*											window;

			public:
				GuiWindowTemplate_StyleProvider(TemplateProperty<GuiWindowTemplate> factory);
				~GuiWindowTemplate_StyleProvider();

				void															AttachWindow(controls::GuiWindow* _window)override;
				void															InitializeNativeWindowProperties()override;
				void															SetSizeState(INativeWindow::WindowSizeState value)override;
				bool															GetMaximizedBox()override;
				void															SetMaximizedBox(bool visible)override;
				bool															GetMinimizedBox()override;
				void															SetMinimizedBox(bool visible)override;
				bool															GetBorder()override;
				void															SetBorder(bool visible)override;
				bool															GetSizeBox()override;
				void															SetSizeBox(bool visible)override;
				bool															GetIconVisible()override;
				void															SetIconVisible(bool visible)override;
				bool															GetTitleBar()override;
				void															SetTitleBar(bool visible)override;
				controls::GuiWindow::IStyleController*							CreateTooltipStyle()override;
				controls::GuiLabel::IStyleController*							CreateShortcutKeyStyle()override;
			};

			class GuiButtonTemplate_StyleProvider
				: public GuiControlTemplate_StyleProvider
				, public virtual controls::GuiButton::IStyleController
				, public Description<GuiButtonTemplate_StyleProvider>
			{
			protected:
				GuiButtonTemplate*												controlTemplate;

			public:
				GuiButtonTemplate_StyleProvider(TemplateProperty<GuiButtonTemplate> factory);
				~GuiButtonTemplate_StyleProvider();

				void															Transfer(controls::GuiButton::ControlState value)override;
			};

			class GuiSelectableButtonTemplate_StyleProvider
				: public GuiButtonTemplate_StyleProvider
				, public virtual controls::GuiSelectableButton::IStyleController
				, public Description<GuiSelectableButtonTemplate_StyleProvider>
			{
			protected:
				GuiSelectableButtonTemplate*									controlTemplate;

			public:
				GuiSelectableButtonTemplate_StyleProvider(TemplateProperty<GuiSelectableButtonTemplate> factory);
				~GuiSelectableButtonTemplate_StyleProvider();

				void															SetSelected(bool value)override;
			};

			class GuiToolstripButtonTemplate_StyleProvider
				: public GuiSelectableButtonTemplate_StyleProvider
				, public virtual controls::GuiMenuButton::IStyleController
				, public Description<GuiToolstripButtonTemplate_StyleProvider>
			{
			protected:
				GuiToolstripButtonTemplate*										controlTemplate;

			public:
				GuiToolstripButtonTemplate_StyleProvider(TemplateProperty<GuiToolstripButtonTemplate> factory);
				~GuiToolstripButtonTemplate_StyleProvider();
				
				controls::GuiMenu::IStyleController*							CreateSubMenuStyleController()override;
				void															SetSubMenuExisting(bool value)override;
				void															SetSubMenuOpening(bool value)override;
				controls::GuiButton*											GetSubMenuHost()override;
				void															SetImage(Ptr<GuiImageData> value)override;
				void															SetShortcutText(const WString& value)override;
			};

			class GuiListViewColumnHeaderTemplate_StyleProvider
				: public GuiToolstripButtonTemplate_StyleProvider
				, public virtual controls::GuiListViewColumnHeader::IStyleController
				, public Description<GuiListViewColumnHeaderTemplate_StyleProvider>
			{
			protected:
				GuiListViewColumnHeaderTemplate*								controlTemplate;

			public:
				GuiListViewColumnHeaderTemplate_StyleProvider(TemplateProperty<GuiListViewColumnHeaderTemplate> factory);
				~GuiListViewColumnHeaderTemplate_StyleProvider();

				void															SetColumnSortingState(controls::GuiListViewColumnHeader::ColumnSortingState value)override;
			};

			class GuiComboBoxTemplate_StyleProvider
				: public GuiToolstripButtonTemplate_StyleProvider
				, public virtual controls::GuiComboBoxListControl::IStyleController
				, public Description<GuiComboBoxTemplate_StyleProvider>
			{
			protected:
				GuiComboBoxTemplate*											controlTemplate;

			public:
				GuiComboBoxTemplate_StyleProvider(TemplateProperty<GuiComboBoxTemplate> factory);
				~GuiComboBoxTemplate_StyleProvider();
				
				void															SetCommandExecutor(controls::GuiComboBoxBase::ICommandExecutor* value)override;
				void															OnItemSelected()override;
				void															SetTextVisible(bool value)override;
			};

			class GuiScrollTemplate_StyleProvider
				: public GuiControlTemplate_StyleProvider
				, public virtual controls::GuiScroll::IStyleController
				, public Description<GuiScrollTemplate_StyleProvider>
			{
			protected:
				GuiScrollTemplate*												controlTemplate;

			public:
				GuiScrollTemplate_StyleProvider(TemplateProperty<GuiScrollTemplate> factory);
				~GuiScrollTemplate_StyleProvider();

				void															SetCommandExecutor(controls::GuiScroll::ICommandExecutor* value)override;
				void															SetTotalSize(vint value)override;
				void															SetPageSize(vint value)override;
				void															SetPosition(vint value)override;
			};

			class GuiScrollViewTemplate_StyleProvider
				: public GuiControlTemplate_StyleProvider
				, public virtual controls::GuiScrollView::IStyleProvider
				, public Description<GuiScrollViewTemplate_StyleProvider>
			{
			protected:
				GuiScrollViewTemplate*											controlTemplate;
				
			public:
				GuiScrollViewTemplate_StyleProvider(TemplateProperty<GuiScrollViewTemplate> factory);
				~GuiScrollViewTemplate_StyleProvider();
				
				controls::GuiScroll::IStyleController*							CreateHorizontalScrollStyle()override;
				controls::GuiScroll::IStyleController*							CreateVerticalScrollStyle()override;
				vint															GetDefaultScrollSize()override;
				compositions::GuiGraphicsComposition*							InstallBackground(compositions::GuiBoundsComposition* boundsComposition)override;
			};

			class GuiMultilineTextBoxTemplate_StyleProvider
				: public GuiScrollViewTemplate_StyleProvider
				, public Description<GuiMultilineTextBoxTemplate_StyleProvider>
			{
			protected:
				GuiMultilineTextBoxTemplate*									controlTemplate;
				
			public:
				GuiMultilineTextBoxTemplate_StyleProvider(TemplateProperty<GuiMultilineTextBoxTemplate> factory);
				~GuiMultilineTextBoxTemplate_StyleProvider();
				
				void															SetFocusableComposition(compositions::GuiGraphicsComposition* value)override;
			};

			class GuiDocumentViewerTemplate_StyleProvider
				: public GuiScrollViewTemplate_StyleProvider
				, public virtual controls::GuiDocumentViewer::IStyleProvider
				, public Description<GuiDocumentViewerTemplate_StyleProvider>
			{
			protected:
				GuiDocumentViewerTemplate*										controlTemplate;
				
			public:
				GuiDocumentViewerTemplate_StyleProvider(TemplateProperty<GuiDocumentViewerTemplate> factory);
				~GuiDocumentViewerTemplate_StyleProvider();
				
				Ptr<DocumentModel>												GetBaselineDocument()override;
				Color															GetCaretColor()override;
			};

			class GuiTextListTemplate_StyleProvider
				: public GuiScrollViewTemplate_StyleProvider
				, public virtual controls::GuiVirtualTextList::IStyleProvider
				, public Description<GuiTextListTemplate_StyleProvider>
			{
			protected:
				GuiTextListTemplate*											controlTemplate;
				
				class ItemStyleProvider
					: public Object
					, public virtual controls::list::TextItemStyleProvider::IBulletFactory
				{
				protected:
					GuiTextListTemplate_StyleProvider*							styleProvider;

				public:
					ItemStyleProvider(GuiTextListTemplate_StyleProvider* _styleProvider);
					~ItemStyleProvider();

					controls::GuiSelectableButton::IStyleController*			CreateBulletStyleController()override;
				};
			public:
				GuiTextListTemplate_StyleProvider(TemplateProperty<GuiTextListTemplate> factory);
				~GuiTextListTemplate_StyleProvider();
				
				controls::GuiSelectableButton::IStyleController*				CreateItemBackground()override;
				Color															GetTextColor()override;
				
				controls::list::TextItemStyleProvider::IBulletFactory*			CreateArgument();
				controls::GuiSelectableButton::IStyleController*				CreateBulletStyle();
			};

			class GuiListViewTemplate_StyleProvider
				: public GuiScrollViewTemplate_StyleProvider
				, public virtual controls::GuiListViewBase::IStyleProvider
				, public Description<GuiListViewTemplate_StyleProvider>
			{
			protected:
				GuiListViewTemplate*											controlTemplate;
				
			public:
				GuiListViewTemplate_StyleProvider(TemplateProperty<GuiListViewTemplate> factory);
				~GuiListViewTemplate_StyleProvider();
				
				controls::GuiSelectableButton::IStyleController*				CreateItemBackground()override;
				controls::GuiListViewColumnHeader::IStyleController*			CreateColumnStyle()override;
				Color															GetPrimaryTextColor()override;
				Color															GetSecondaryTextColor()override;
				Color															GetItemSeparatorColor()override;
			};

			class GuiTreeViewTemplate_StyleProvider
				: public GuiScrollViewTemplate_StyleProvider
				, public virtual controls::GuiVirtualTreeView::IStyleProvider
				, public Description<GuiTreeViewTemplate_StyleProvider>
			{
			protected:
				GuiTreeViewTemplate*											controlTemplate;
				
			public:
				GuiTreeViewTemplate_StyleProvider(TemplateProperty<GuiTreeViewTemplate> factory);
				~GuiTreeViewTemplate_StyleProvider();
				
				controls::GuiSelectableButton::IStyleController*				CreateItemBackground()override;
				controls::GuiSelectableButton::IStyleController*				CreateItemExpandingDecorator()override;
				Color															GetTextColor()override;
			};

			class GuiTabTemplate_StyleProvider
				: public GuiControlTemplate_StyleProvider
				, public virtual controls::GuiTab::IStyleController
				, public Description<GuiTabTemplate_StyleProvider>
			{
			protected:
				GuiTabTemplate*													controlTemplate;
				
				compositions::GuiTableComposition*								tabBoundsComposition;
				compositions::GuiStackComposition*								tabHeaderComposition;
				compositions::GuiBoundsComposition*								tabContentTopLineComposition;
				controls::GuiTab::ICommandExecutor*								commandExecutor;

				Ptr<controls::GuiSelectableButton::MutexGroupController>		headerController;
				collections::List<controls::GuiSelectableButton*>				headerButtons;
				controls::GuiButton*											headerOverflowButton;
				controls::GuiToolstripMenu*										headerOverflowMenu;
				
				controls::GuiSelectableButton::IStyleController*				CreateHeaderTemplate();
				controls::GuiButton::IStyleController*							CreateDropdownTemplate();
				controls::GuiMenu::IStyleController*							CreateMenuTemplate();
				controls::GuiToolstripButton::IStyleController*					CreateMenuItemTemplate();

				void															OnHeaderButtonClicked(compositions::GuiGraphicsComposition* sender, compositions::GuiEventArgs& arguments);
				void															OnTabHeaderBoundsChanged(compositions::GuiGraphicsComposition* sender, compositions::GuiEventArgs& arguments);
				void															OnHeaderOverflowButtonClicked(compositions::GuiGraphicsComposition* sender, compositions::GuiEventArgs& arguments);
				void															OnHeaderOverflowMenuButtonClicked(compositions::GuiGraphicsComposition* sender, compositions::GuiEventArgs& arguments);

				void															UpdateHeaderOverflowButtonVisibility();
				void															UpdateHeaderZOrder();
				void															UpdateHeaderVisibilityIndex();
				void															UpdateHeaderLayout();

				void															Initialize();
			public:
				GuiTabTemplate_StyleProvider(TemplateProperty<GuiTabTemplate> factory);
				~GuiTabTemplate_StyleProvider();

				void															SetCommandExecutor(controls::GuiTab::ICommandExecutor* value)override;
				void															InsertTab(vint index)override;
				void															SetTabText(vint index, const WString& value)override;
				void															RemoveTab(vint index)override;
				void															MoveTab(vint oldIndex, vint newIndex)override;
				void															SetSelectedTab(vint index)override;
				void															SetTabAlt(vint index, const WString& value, compositions::IGuiAltActionHost* host)override;
				compositions::IGuiAltAction*									GetTabAltAction(vint index)override;
			};

			class GuiDatePickerTemplate_StyleProvider
				: public GuiControlTemplate_StyleProvider
				, public virtual controls::GuiDatePicker::IStyleProvider
				, public Description<GuiDatePickerTemplate_StyleProvider>
			{
			protected:
				GuiDatePickerTemplate*											controlTemplate;

			public:
				GuiDatePickerTemplate_StyleProvider(TemplateProperty<GuiDatePickerTemplate> factory);
				~GuiDatePickerTemplate_StyleProvider();

				controls::GuiSelectableButton::IStyleController*				CreateDateButtonStyle()override;
				GuiTextListTemplate_StyleProvider*								CreateTextListStyle();
				controls::GuiTextList*											CreateTextList()override;
				controls::GuiComboBoxListControl::IStyleController*				CreateComboBoxStyle()override;
				Color															GetBackgroundColor()override;
				Color															GetPrimaryTextColor()override;
				Color															GetSecondaryTextColor()override;
			};

			class GuiDateComboBoxTemplate_StyleProvider
				: public GuiComboBoxTemplate_StyleProvider
				, public Description<GuiDateComboBoxTemplate_StyleProvider>
			{
			protected:
				GuiDateComboBoxTemplate*										controlTemplate;

			public:
				GuiDateComboBoxTemplate_StyleProvider(TemplateProperty<GuiDateComboBoxTemplate> factory);
				~GuiDateComboBoxTemplate_StyleProvider();

				controls::GuiDatePicker*										CreateArgument();
				controls::GuiDatePicker::IStyleProvider*						CreateDatePickerStyle();
			};

/***********************************************************************
Item Template (GuiControlTemplate)
***********************************************************************/

			class GuiControlTemplate_ItemStyleProvider
				: public Object
				, public virtual controls::GuiComboBoxListControl::IItemStyleProvider
				, public Description<GuiControlTemplate_ItemStyleProvider>
			{
			protected:
				TemplateProperty<GuiControlTemplate>				factory;

			public:
				GuiControlTemplate_ItemStyleProvider(TemplateProperty<GuiControlTemplate> _factory);
				~GuiControlTemplate_ItemStyleProvider();

				void												AttachComboBox(controls::GuiComboBoxListControl* value)override;
				void												DetachComboBox()override;
				controls::GuiControl::IStyleController*				CreateItemStyle(description::Value item)override;
			};

/***********************************************************************
Item Template (GuiTextListItemTemplate)
***********************************************************************/

			class GuiTextListItemTemplate_ItemStyleController;

			class GuiTextListItemTemplate_ItemStyleProvider
				: public Object
				, public virtual controls::GuiSelectableListControl::IItemStyleProvider
				, public Description<GuiTextListItemTemplate_ItemStyleProvider>
			{
				friend class GuiTextListItemTemplate_ItemStyleController;
			protected:
				TemplateProperty<GuiTextListItemTemplate>			factory;
				controls::GuiVirtualTextList*						listControl = nullptr;

			public:
				GuiTextListItemTemplate_ItemStyleProvider(TemplateProperty<GuiTextListItemTemplate> _factory);
				~GuiTextListItemTemplate_ItemStyleProvider();

				void												AttachListControl(controls::GuiListControl* value)override;
				void												DetachListControl()override;
				controls::GuiListControl::IItemStyleController*		CreateItemStyle()override;
				void												DestroyItemStyle(controls::GuiListControl::IItemStyleController* style)override;
				void												Install(controls::GuiListControl::IItemStyleController* style, vint itemIndex)override;
				void												SetStyleIndex(controls::GuiListControl::IItemStyleController* style, vint value)override;
				void												SetStyleSelected(controls::GuiListControl::IItemStyleController* style, bool value)override;
			};

			class GuiTextListItemTemplate_ItemStyleController
				: public Object
				, public virtual controls::GuiListControl::IItemStyleController
				, public Description<GuiTextListItemTemplate_ItemStyleController>
			{
				friend class GuiTextListItemTemplate_ItemStyleProvider;
			protected:
				GuiTextListItemTemplate_ItemStyleProvider*			itemStyleProvider;
				GuiTextListItemTemplate*							itemTemplate;
				bool												installed;
				controls::GuiSelectableButton*						backgroundButton;

			public:
				GuiTextListItemTemplate_ItemStyleController(GuiTextListItemTemplate_ItemStyleProvider* _itemStyleProvider);
				~GuiTextListItemTemplate_ItemStyleController();

				GuiTextListItemTemplate*							GetTemplate();
				void												SetTemplate(GuiTextListItemTemplate* _itemTemplate);

				controls::GuiListControl::IItemStyleProvider*		GetStyleProvider()override;
				vint												GetItemStyleId()override;
				compositions::GuiBoundsComposition*					GetBoundsComposition()override;
				bool												IsCacheable()override;
				bool												IsInstalled()override;
				void												OnInstalled()override;
				void												OnUninstalled()override;
			};

/***********************************************************************
Item Template (GuiTreeItemTemplate)
***********************************************************************/

			class GuiTreeItemTemplate_ItemStyleController;

			class GuiTreeItemTemplate_ItemStyleProvider
				: public Object
				, public virtual controls::tree::INodeItemStyleProvider
				, protected virtual controls::tree::INodeProviderCallback
				, public Description<GuiTreeItemTemplate_ItemStyleProvider>
			{
				friend class GuiTreeItemTemplate_ItemStyleController;
			protected:
				TemplateProperty<GuiTreeItemTemplate>				factory;
				controls::GuiVirtualTreeListControl*				treeListControl = nullptr;
				controls::GuiListControl::IItemStyleProvider*		itemStyleProvider = nullptr;
				
				void												UpdateExpandingButton(controls::tree::INodeProvider* node);
				void												OnAttached(controls::tree::INodeRootProvider* provider)override;
				void												OnBeforeItemModified(controls::tree::INodeProvider* parentNode, vint start, vint count, vint newCount)override;
				void												OnAfterItemModified(controls::tree::INodeProvider* parentNode, vint start, vint count, vint newCount)override;
				void												OnItemExpanded(controls::tree::INodeProvider* node)override;
				void												OnItemCollapsed(controls::tree::INodeProvider* node)override;

			public:
				GuiTreeItemTemplate_ItemStyleProvider(TemplateProperty<GuiTreeItemTemplate> _factory);
				~GuiTreeItemTemplate_ItemStyleProvider();
				
				void												BindItemStyleProvider(controls::GuiListControl::IItemStyleProvider* styleProvider)override;
				controls::GuiListControl::IItemStyleProvider*		GetBindedItemStyleProvider()override;
				void												AttachListControl(controls::GuiListControl* value)override;
				void												DetachListControl()override;
				controls::tree::INodeItemStyleController*			CreateItemStyle()override;
				void												DestroyItemStyle(controls::tree::INodeItemStyleController* style)override;
				void												Install(controls::tree::INodeItemStyleController* style, controls::tree::INodeProvider* node, vint itemIndex)override;
				void												SetStyleIndex(controls::tree::INodeItemStyleController* style, vint value)override;
				void												SetStyleSelected(controls::tree::INodeItemStyleController* style, bool value)override;
			};
			
			class GuiTreeItemTemplate_ItemStyleController
				: public Object
				, public virtual controls::tree::INodeItemStyleController
				, public Description<GuiTreeItemTemplate_ItemStyleController>
			{
				friend class GuiTreeItemTemplate_ItemStyleProvider;
			protected:
				GuiTreeItemTemplate_ItemStyleProvider*				nodeStyleProvider;
				GuiTreeItemTemplate*								itemTemplate;
				bool												installed;

			public:
				GuiTreeItemTemplate_ItemStyleController(GuiTreeItemTemplate_ItemStyleProvider* _nodeStyleProvider);
				~GuiTreeItemTemplate_ItemStyleController();

				GuiTreeItemTemplate*								GetTemplate();
				void												SetTemplate(GuiTreeItemTemplate* _itemTemplate);
				
				controls::GuiListControl::IItemStyleProvider*		GetStyleProvider()override;
				vint												GetItemStyleId()override;
				compositions::GuiBoundsComposition*					GetBoundsComposition()override;
				bool												IsCacheable()override;
				bool												IsInstalled()override;
				void												OnInstalled()override;
				void												OnUninstalled()override;
				controls::tree::INodeItemStyleProvider*				GetNodeStyleProvider()override;
			};

/***********************************************************************
Item Template (GuiGridVisualizerTemplate)
***********************************************************************/

			/// <summary>Data visualizer object for [T:vl.presentation.controls.GuiBindableDataGrid].</summary>
			class GuiBindableDataVisualizer : public controls::list::DataVisualizerBase, public Description<GuiBindableDataVisualizer>
			{
			public:
				class Factory : public controls::list::DataVisualizerFactory<GuiBindableDataVisualizer>
				{
				protected:
					TemplateProperty<GuiGridVisualizerTemplate>		templateFactory;

				public:
					Factory(TemplateProperty<GuiGridVisualizerTemplate> _templateFactory);
					~Factory();

					Ptr<controls::list::IDataVisualizer>			CreateVisualizer(const FontProperties& font, controls::GuiListViewBase::IStyleProvider* styleProvider, const description::Value& viewModelContext)override;
				};

				class DecoratedFactory : public controls::list::DataDecoratableVisualizerFactory<GuiBindableDataVisualizer>
				{
				protected:
					TemplateProperty<GuiGridVisualizerTemplate>		templateFactory;

				public:
					DecoratedFactory(TemplateProperty<GuiGridVisualizerTemplate> _templateFactory, Ptr<controls::list::IDataVisualizerFactory> _decoratedFactory);
					~DecoratedFactory();

					Ptr<controls::list::IDataVisualizer>			CreateVisualizer(const FontProperties& font, controls::GuiListViewBase::IStyleProvider* styleProvider, const description::Value& viewModelContext)override;
				};

			protected:
				TemplateProperty<GuiGridVisualizerTemplate>			templateFactory;
				GuiGridVisualizerTemplate*							visualizerTemplate = nullptr;

				compositions::GuiBoundsComposition*					CreateBoundsCompositionInternal(compositions::GuiBoundsComposition* decoratedComposition)override;
			public:
				GuiBindableDataVisualizer();
				GuiBindableDataVisualizer(Ptr<controls::list::IDataVisualizer> _decoratedVisualizer);
				~GuiBindableDataVisualizer();

				void												BeforeVisualizeCell(controls::list::IDataProvider* dataProvider, vint row, vint column)override;
				void												SetSelected(bool value)override;
			};

/***********************************************************************
Item Template (GuiGridEditorTemplate)
***********************************************************************/

			class GuiBindableDataEditor : public controls::list::DataEditorBase, public Description<GuiBindableDataEditor>
			{
			public:
				class Factory : public controls::list::DataEditorFactory<GuiBindableDataEditor>
				{
				protected:
					TemplateProperty<GuiGridEditorTemplate>			templateFactory;

				public:
					Factory(TemplateProperty<GuiGridEditorTemplate> _templateFactory);
					~Factory();

					Ptr<controls::list::IDataEditor>				CreateEditor(controls::list::IDataEditorCallback* callback, const description::Value& viewModelContext)override;
				};

			protected:
				TemplateProperty<GuiGridEditorTemplate>				templateFactory;
				GuiGridEditorTemplate*								editorTemplate = nullptr;

				compositions::GuiBoundsComposition*					CreateBoundsCompositionInternal()override;
				void												editorTemplate_CellValueChanged(compositions::GuiGraphicsComposition* sender, compositions::GuiEventArgs& arguments);
			public:
				GuiBindableDataEditor();
				~GuiBindableDataEditor();

				void												BeforeEditCell(controls::list::IDataProvider* dataProvider, vint row, vint column)override;
				description::Value									GetEditedCellValue();
			};

/***********************************************************************
Helper Functions
***********************************************************************/

			extern void												SplitBySemicolon(const WString& input, collections::List<WString>& fragments);

#pragma warning(pop)
		}
	}
}

#endif