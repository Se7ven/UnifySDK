///////////////////////////////////////////////////////////////////////////////
// # License
// <b>Copyright 2022  Silicon Laboratories Inc. www.silabs.com</b>
///////////////////////////////////////////////////////////////////////////////
// The licensor of this software is Silicon Laboratories Inc. Your use of this
// software is governed by the terms of Silicon Labs Master Software License
// Agreement (MSLA) available at
// www.silabs.com/about-us/legal/master-software-license-agreement. This
// software is distributed to you in Source Code format and is governed by the
// sections of the MSLA applicable to Source Code.
//
///////////////////////////////////////////////////////////////////////////////
///
use async_trait::async_trait;
use unify_middleware::Attribute;
use unify_middleware::AttributeEvent;

#[cfg_attr(test, mockall::automock)]
#[async_trait]
pub trait AttributeWatcherTrait {
    async fn next_change(&mut self) -> AttributeEvent<Attribute>;
}
